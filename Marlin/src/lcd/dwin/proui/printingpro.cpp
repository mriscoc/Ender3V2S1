/**
 * Professional Firmware UI extensions - Print screen (open source replacement)
 *
 * Open re-implementation of the PrintingPro screen that ships precompiled in
 * Marlin/lib/proui (printingpro.cpp.o). Same layout and temperature plot, with:
 *  - correct elapsed time beyond 18.2 h (the original truncated seconds to 16 bit)
 *  - a single clean "Stopping..." state after a confirmed Stop, instead of redrawing
 *    the whole print screen just before the "done" screen replaces it
 *  - "Print Aborted" instead of "Print Done" after a stop
 *  - Pause/Resume button and action use the same paused state
 *  - values are redrawn only when the displayed text changes
 *
 * Because this file defines every symbol of the library module, the linker never
 * pulls printingpro.cpp.o out of libproui.a (it is a normal -lproui archive).
 * Define PROUI_LIB_PRINTSCREEN to use the original library version instead.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

#include "../../../inc/MarlinConfig.h"

#if ALL(DWIN_LCD_PROUI, PROUI_EX, HAS_PLOT) && DISABLED(PROUI_LIB_PRINTSCREEN)

#include "../../marlinui.h"
#include "../../../module/temperature.h"
#include "../../../module/printcounter.h"
#include "dwin.h"
#include "dwin_popup.h"
#include "plot.h"
#include "printing.h"

select_t select_print{0};
PrintingPro printing;

// Layout (same coordinates as the library version)
static constexpr frame_rect_t frmTune  = {   8, 232, 80, 100 },
                              frmPause = {  96, 232, 80, 100 },
                              frmStop  = { 184, 232, 80, 100 },
                              frmPlot  = {  10, 120, 252, 90 };
static constexpr uint16_t VALUES_Y = 60, ELAPSED_X = 47, REMAIN_X = 181,
                          PERCENT_X = 10, PERCENT_Y = 90,
                          BAR_X1 = 55, BAR_X2 = 255, BAR_Y1 = 92, BAR_Y2 = 102;
static constexpr uint16_t PLOT_POINTS = 252;                 // == frmPlot.w
static constexpr uint16_t BED_PLOT_COLOR = COLOR_LIGHT_GREEN; // hotend uses the Plot data color
static constexpr millis_t STOP_FALLBACK_MS = 15000;           // give up "Stopping..." if the job never ends

static char printtitle[32] = "";
static bool titleChanged = true;
static bool donehasPreview = false;
static bool stopRequested = false;   // a Stop was confirmed and the job is ending
static millis_t stopRequested_ms = 0;

// Temperature history (hotend, bed) for the plot, as a ring buffer
static int16_t hpl[PLOT_POINTS], bpl[PLOT_POINTS];
static uint16_t point = 0;
static bool plfull = false;

static bool isPausedState() { return print_job_timer.isPaused() || hmiFlag.pause_flag; }

//
// Buttons
//
static void iconTune() {
  iconButton(select_print.now == PRINT_TUNE, ICON_Setup_0, frmTune, GET_TEXT_F(MSG_TUNE));
}
static void iconPause() {
  iconButton(select_print.now == PRINT_PAUSE_RESUME, ICON_Pause_0, frmPause, GET_TEXT_F(MSG_BUTTON_PAUSE));
}
static void iconResume() {
  iconButton(select_print.now == PRINT_PAUSE_RESUME, ICON_Continue_0, frmPause, GET_TEXT_F(MSG_BUTTON_RESUME));
}
static void iconResumeOrPause() { isPausedState() ? iconResume() : iconPause(); }
static void iconStop() {
  iconButton(select_print.now == PRINT_STOP, ICON_Stop_0, frmStop, GET_TEXT_F(MSG_BUTTON_STOP));
}

//
// Pause / Stop confirmation
//
static void onClickPauseOrStop() {
  if (hmiFlag.select_flag) switch (select_print.now) {
    case PRINT_PAUSE_RESUME: ui.pause_print(); break;
    case PRINT_STOP:
      stopRequested = true;
      stopRequested_ms = millis();
      ui.abort_print();
      break;
    default: break;
  }
  gotoPrintProcess(); // Leaves the popup: full print screen, or the "Stopping..." screen
}

static void popupPauseOrStop() {
  dwinPopupConfirmCancel(ICON_BLTouch, select_print.now == PRINT_PAUSE_RESUME ? GET_TEXT_F(MSG_PAUSE_PRINT) : GET_TEXT_F(MSG_STOP_PRINT));
}

//
// Labels, values, progress bar
//
static void drawPrintLabels() {
  DWINUI::iconShow(false, ICON_PrintTime, 15, 42);
  DWINUI::drawString(46, 42, GET_TEXT_F(MSG_INFO_PRINT_TIME));
  DWINUI::iconShow(false, ICON_RemainTime, 150, 40);
  DWINUI::drawString(181, 42, GET_TEXT_F(MSG_REMAINING_TIME));
}

// "HH:MM" from seconds; two trailing spaces erase leftovers when the text gets shorter (e.g. 100:05 -> 17:05)
static void drawTime(const uint16_t x, const uint32_t seconds) {
  char buf[16];
  snprintf_P(buf, sizeof(buf), PSTR("%02u:%02u  "), unsigned(seconds / 3600), unsigned((seconds % 3600) / 60));
  dwinDrawString(true, DWINUI::fontID, hmiData.colorText, hmiData.colorBackground, x, VALUES_Y, buf);
}

static void drawPrintProgressElapsed() { drawTime(ELAPSED_X, print_job_timer.duration()); }
static void drawPrintProgressRemain()  { drawTime(REMAIN_X, ui.get_remaining_time()); }

static void drawPrintProgressBar() {
  const uint8_t pct = _MIN(ui.get_progress_percent(), 100U);
  DWINUI::drawInt(true, false, DWINUI::fontID, hmiData.colorPercentTxt, hmiData.colorBackground, 3, PERCENT_X, PERCENT_Y, pct);
  dwinDrawString(false, DWINUI::fontID, hmiData.colorPercentTxt, hmiData.colorBackground, PERCENT_X + 25, PERCENT_Y, F("%"));
  const uint16_t xp = BAR_X1 + pct * (BAR_X2 - BAR_X1) / 100;
  if (xp > BAR_X1) dwinDrawRectangle(1, hmiData.colorPercentTxt, BAR_X1, BAR_Y1, xp, BAR_Y2);
  if (xp < BAR_X2) dwinDrawRectangle(1, hmiData.colorBarfill, xp, BAR_Y1, BAR_X2, BAR_Y2);
}

static void drawPrintTitle() { title.draw(printtitle); }

//
// Temperature plot
//
static void drawPoints(const uint16_t i) {
  plot.update(hpl[i]);
  plot.putPoint(BED_PLOT_COLOR, bpl[i]);
}

// Record the current temperatures and draw them
static void drawPoints() {
  hpl[point] = int16_t(thermalManager.degHotend(0) + 0.5f);
  bpl[point] = int16_t(TERN0(HAS_HEATED_BED, thermalManager.degBed()) + 0.5f);
  drawPoints(point);
  if (++point >= PLOT_POINTS) { point = 0; plfull = true; }
}

// Redraw the whole history (after the plot frame was redrawn), oldest first
static void fillPlot() {
  const uint16_t n = plfull ? PLOT_POINTS : point;
  for (uint16_t i = 0; i < n; ++i) {
    uint16_t idx = plfull ? point + i : i;
    if (idx >= PLOT_POINTS) idx -= PLOT_POINTS;
    drawPoints(idx);
  }
}

static void drawPlotFrame() { plot.draw(frmPlot, thermalManager.hotend_maxtemp[0]); }

static void drawStopping() {
  DWINUI::clearMainArea();
  DWINUI::drawCenteredString(true, DWINUI::fontID, hmiData.colorText, hmiData.colorBackground, 150, GET_TEXT_F(MSG_STOPPING));
}

//
// PrintingPro interface (see printing.h)
//
void PrintingPro::setPrintTitle(const char *text) {
  strlcpy(printtitle, text ?: "", sizeof(printtitle));
  titleChanged = true;
  stopRequested = false; // A new job is starting
}

void PrintingPro::printUpdate(bool force) {
  if (stopRequested) {
    // Wait for the done screen; fall back to the normal screen if the job does not end (e.g. host print)
    if (ELAPSED(millis(), stopRequested_ms + STOP_FALLBACK_MS)) { stopRequested = false; drawPrintProcess(); }
    return;
  }

  // After the backlight comes back, redraw everything: values that only change rarely
  // (remaining time once per layer) would otherwise stay blank until their next change.
  #if HAS_LCD_BRIGHTNESS
    static bool _backlightOn = true;
    if (ui.backlight != _backlightOn) { _backlightOn = ui.backlight; force |= ui.backlight; }
  #endif

  if (force || titleChanged) { titleChanged = false; drawPrintTitle(); }

  static bool _paused = false;
  const bool paused = isPausedState();
  if (force || _paused != paused) { _paused = paused; iconResumeOrPause(); }

  static uint8_t _percent = 255;
  const uint8_t pct = ui.get_progress_percent();
  if (force || _percent != pct) { _percent = pct; drawPrintProgressBar(); }

  // The two time values are cheap (one short text each) and change rarely, so they are simply
  // redrawn on every update (about once a second). That also heals them if the display lost them.
  drawPrintProgressRemain();
  drawPrintProgressElapsed();

  drawPoints();
}

void PrintingPro::drawPrintProcess() {
  if (stopRequested) { drawPrintTitle(); drawStopping(); dwinUpdateLCD(); return; }
  DWINUI::clearMainArea();
  drawPrintLabels();
  drawPlotFrame();
  iconTune();
  iconResumeOrPause();
  iconStop();
  dwinUpdateLCD();
  fillPlot();
  printUpdate(true);
}

void PrintingPro::drawPrintDone() {
  const bool stopped = stopRequested;
  stopRequested = false;
  __set_progress_done();
  __reset_remaining_time();
  DWINUI::clearMainArea();
  drawPrintTitle();
  donehasPreview = __hasPreview();
  if (donehasPreview) {
    __showPreview();
    DWINUI::drawButton(BTN_Continue, 86, 295);
  }
  else {
    drawPrintLabels();
    drawPrintProgressElapsed();
    drawPrintProgressRemain();
    drawPrintProgressBar();
    drawPlotFrame();
    fillPlot();
    DWINUI::drawButton(BTN_Continue, 86, 273);
  }
  ui.set_status(stopped ? GET_TEXT_F(MSG_PRINT_ABORTED) : GET_TEXT_F(MSG_PRINT_DONE));
}

void PrintingPro::doneUpdate() {
  if (!donehasPreview) drawPoints(); // Keep plotting the cool-down
}

void PrintingPro::hmiPrinting() {
  const EncoderState encoder_diffState = get_encoder_state();
  if (encoder_diffState == ENCODER_DIFF_NO || stopRequested) return;

  if (encoder_diffState == ENCODER_DIFF_CW) {
    if (select_print.inc(PRINT_COUNT)) switch (select_print.now) {
      case PRINT_PAUSE_RESUME: iconTune(); iconResumeOrPause(); break;
      case PRINT_STOP: iconResumeOrPause(); iconStop(); break;
      default: break;
    }
  }
  else if (encoder_diffState == ENCODER_DIFF_CCW) {
    if (select_print.dec()) switch (select_print.now) {
      case PRINT_TUNE: iconTune(); iconResumeOrPause(); break;
      case PRINT_PAUSE_RESUME: iconResumeOrPause(); iconStop(); break;
      default: break;
    }
  }
  else if (encoder_diffState == ENCODER_DIFF_ENTER) {
    switch (select_print.now) {
      case PRINT_TUNE: drawTuneMenu(); break;
      case PRINT_PAUSE_RESUME:
        if (isPausedState()) { ui.resume_print(); break; }
        return gotoPopup(popupPauseOrStop, onClickPauseOrStop);
      case PRINT_STOP: return gotoPopup(popupPauseOrStop, onClickPauseOrStop);
      default: break;
    }
  }
  dwinUpdateLCD();
}

#endif // DWIN_LCD_PROUI && PROUI_EX && HAS_PLOT && !PROUI_LIB_PRINTSCREEN
