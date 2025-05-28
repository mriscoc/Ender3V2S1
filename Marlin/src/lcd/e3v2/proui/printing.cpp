/**
 * DWIN Printing screen implementation
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 1.1.1
 * Date: 2025/01/02
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfig.h"

#if ALL(DWIN_LCD_PROUI) && (DISABLED(PROUI_EX) || DISABLED(HAS_PLOT))

#if HAS_GCODE_PREVIEW
  #include "gcode_preview.h"
#endif

#include "../../marlinui.h"
#include "dwin_popup.h"
#include "printing.h"
#include "dwin.h"

#define DEBUG_OUT ENABLED(DEBUG_DWIN)
#include "../../../core/debug_out.h"

select_t select_print{0};
MString<31> printtitle = "";  // Print header text

Printing printing;

//
// Printing: "Tune"
//
void iconTune() {
  constexpr frame_rect_t ico = { 8, 232, 80, 100 };
  iconButton(select_print.now == PRINT_TUNE, ICON_Setup_0, ico, GET_TEXT_F(MSG_TUNE));
}


//
// Printing: "Pause"
//
void iconPause() {
  constexpr frame_rect_t ico = { 96, 232, 80, 100 };
  iconButton(select_print.now == PRINT_PAUSE_RESUME, ICON_Pause_0, ico, GET_TEXT_F(MSG_BUTTON_PAUSE));
}

//
// Printing: "Resume"
//
void iconResume() {
  constexpr frame_rect_t ico = { 96, 232, 80, 100 };
  iconButton(select_print.now == PRINT_PAUSE_RESUME, ICON_Continue_0, ico, GET_TEXT_F(MSG_BUTTON_RESUME));
}

//
// Printing: "Stop"
//
void iconStop() {
  constexpr frame_rect_t ico = { 184, 232, 80, 100 };
  iconButton(select_print.now == PRINT_STOP, ICON_Stop_0, ico, GET_TEXT_F(MSG_BUTTON_STOP));
}

//
// Pause or Stop popup
//
void onClickPauseOrStop() {
  switch (select_print.now) {
    case PRINT_PAUSE_RESUME: if (hmiFlag.select_flag) ui.pause_print(); break; // confirm pause
    case PRINT_STOP: if (hmiFlag.select_flag) ui.abort_print(); break; // stop confirmed then abort print
    default: break;
  }
  return gotoPrintProcess();
}

void popupPauseOrStop() {
  dwinPopupConfirmCancel(ICON_BLTouch, select_print.now == PRINT_PAUSE_RESUME ? GET_TEXT_F(MSG_PAUSE_PRINT) : GET_TEXT_F(MSG_STOP_PRINT));
}

void drawPrintLabels() {
  DWINUI::drawIcon(ICON_PrintTime, 15, 173);
  DWINUI::drawString( 46, 173, GET_TEXT_F(MSG_INFO_PRINT_TIME));
  DWINUI::drawIcon(ICON_RemainTime, 150, 171);
  DWINUI::drawString(181, 173, GET_TEXT_F(MSG_REMAINING_TIME));
}

void drawPrintProgressElapsed() {
  MString<12> buf;
  duration_t elapsed = print_job_timer.duration(); // Print timer
  buf.setf(F("%02i:%02i "), uint16_t(elapsed.value / 3600), (uint16_t(elapsed.value) % 3600) / 60);
  DWINUI::drawString(hmiData.colorText, hmiData.colorBackground, 47, 192, buf);
}

#if ENABLED(SHOW_REMAINING_TIME)
  void drawPrintProgressRemain() {
    const uint32_t _remain_time = ui.get_remaining_time();
    MString<12> buf;
    buf.setf(F("%02i:%02i "), _remain_time / 3600, (_remain_time % 3600) / 60);
    DWINUI::drawString(hmiData.colorText, hmiData.colorBackground, 181, 192, buf);
  }
#endif

void drawPrintProgressBar() {
  const uint8_t _percent_done = ui.get_progress_percent();
  DWINUI::drawIconWB(ICON_Bar, 15, 93);
  dwinDrawRectangle(1, hmiData.colorBarfill, 16 + (_percent_done * 240) / 100, 93, 256, 113);
  DWINUI::drawInt(hmiData.colorPercentTxt, hmiData.colorBackground, 3, 117, 133, _percent_done);
  DWINUI::drawString(hmiData.colorPercentTxt, 142, 133, F("%"));
}

void iconResumeOrPause() {
  (print_job_timer.isPaused() || hmiFlag.pause_flag) ? iconResume() : iconPause();
}

void drawPrintTitle(){
  if (checkkey == ID_PrintProcess || checkkey == ID_PrintDone) {
    dwinDrawRectangle(1, hmiData.colorBackground, 0, 60, DWIN_WIDTH, 60+16);
    DWINUI::drawCenteredString(60, printtitle);
  }
}

// Update filename on print
void Printing::setPrintTitle(const char *text) {
  printtitle.set(text);
}

void Printing::printUpdate(bool force) {
  // Update title
  static MString<>::hash_t title_hash = 0x0000;
  const MString<>::hash_t new_hash = printtitle.hash();
  if (force || (title_hash != new_hash)) {
    title_hash = new_hash;
    drawPrintTitle();
  }

  // Icon pause or resume
  static bool _updatepause = true;
  const bool isPaused = (print_job_timer.isPaused() || hmiFlag.pause_flag);
  if (force || (_updatepause != isPaused)) {
    _updatepause = isPaused;
    iconResumeOrPause();
  }

  // Progress percent
  static uint8_t _percent_done = 255;
  if (force || (_percent_done != ui.get_progress_percent())) {
    _percent_done = ui.get_progress_percent();
    drawPrintProgressBar();
  }

  // Remaining time
  #if ENABLED(SHOW_REMAINING_TIME)
    static uint32_t _remain_time = 0;
    if (force || (_remain_time != ui.get_remaining_time())) {
      _remain_time = ui.get_remaining_time();
      drawPrintProgressRemain();
    }
  #endif

  // Elapse print time
  static uint16_t _printtime = 0;
  const uint16_t min = (print_job_timer.duration() % 3600) / 60;
  if (force || (_printtime != min)) { // 1 minute update
    _printtime = min;
    drawPrintProgressElapsed();
  }
}

void Printing::drawPrintProcess() {
  #if ENABLED(CV_LASER_MODULE)
    title.draw(laser_device.is_laser_device() ? GET_TEXT_F(MSG_ENGRAVING) : GET_TEXT_F(MSG_PRINTING));
  #else
    title.draw(GET_TEXT_F(MSG_PRINTING));
  #endif
  DWINUI::clearMainArea();
  drawPrintLabels();
  iconTune();
  iconResumeOrPause();
  iconStop();
  printUpdate(true);
}

void Printing::drawPrintDone() {
  TERN_(SET_PROGRESS_PERCENT, ui.set_progress_done());
  TERN_(SET_REMAINING_TIME, ui.reset_remaining_time());
  DWINUI::clearMainArea();
  drawPrintTitle();
  #if HAS_GCODE_PREVIEW
    const bool haspreview = gPreview.isValid();
    if (haspreview) {
      gPreview.show();
      DWINUI::drawButton(BTN_Continue, 86, 295);
    }
  #else
    constexpr bool haspreview = false;
  #endif

  if (!haspreview) {
    drawPrintLabels();
    drawPrintProgressElapsed();
    TERN_(SHOW_REMAINING_TIME, drawPrintProgressRemain());
    drawPrintProgressBar();
    DWINUI::drawButton(BTN_Continue, 86, 273);
    LCD_MESSAGE(MSG_PRINT_DONE);
  }
}

// Printing
void Printing::hmiPrinting() {
  EncoderState encoder_diffState = get_encoder_state();
  if (encoder_diffState == ENCODER_DIFF_NO) return;
  // Avoid flicker by updating only the previous menu
  if (encoder_diffState == ENCODER_DIFF_CW) {
    if (select_print.inc(PRINT_COUNT)) {
      switch (select_print.now) {
        case PRINT_TUNE: iconTune(); break;
        case PRINT_PAUSE_RESUME: iconTune(); iconResumeOrPause(); break;
        case PRINT_STOP: iconResumeOrPause(); iconStop(); break;
      }
    }
  }
  else if (encoder_diffState == ENCODER_DIFF_CCW) {
    if (select_print.dec()) {
      switch (select_print.now) {
        case PRINT_TUNE: iconTune(); iconResumeOrPause(); break;
        case PRINT_PAUSE_RESUME: iconResumeOrPause(); iconStop(); break;
        case PRINT_STOP: iconStop(); break;
      }
    }
  }
  else if (encoder_diffState == ENCODER_DIFF_ENTER) {
    switch (select_print.now) {
      case PRINT_TUNE: drawTuneMenu(); break;
      case PRINT_PAUSE_RESUME:
        if (print_job_timer.isPaused()) {  // if printer is already in pause
          ui.resume_print();
          break;
        }
        else
          return gotoPopup(popupPauseOrStop, onClickPauseOrStop);
      case PRINT_STOP:
        return gotoPopup(popupPauseOrStop, onClickPauseOrStop);
      default: break;
    }
  }
  dwinUpdateLCD();
}

void Printing::doneUpdate() { }

#endif // DWIN_LCD_PROUI
