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
#pragma once

#include "../../../inc/MarlinConfigPre.h"
#include "../../marlinui.h"
#include "dwin.h"

#if HAS_GCODE_PREVIEW
  #include "gcode_preview.h"
#endif

enum printIcon : uint8_t {
  PRINT_TUNE = 0,
  PRINT_PAUSE_RESUME,
  PRINT_STOP,
  PRINT_COUNT
};

extern select_t select_print;

#if ALL(DWIN_LCD_PROUI, PROUI_EX, HAS_PLOT)
  class PrintingPro {
  public:
    static void setPrintTitle(const char *text = nullptr);
    static void drawPrintProcess();
    static void drawPrintDone();
    static void hmiPrinting();
    static void printUpdate(bool force = false);
    static void doneUpdate();
    #if ENABLED(SET_PROGRESS_PERCENT)
      static void __set_progress_done() { ui.set_progress_done(); }
    #else
      static void __set_progress_done() {}
    #endif
    #if ENABLED(SET_REMAINING_TIME)
      static void __reset_remaining_time() { ui.reset_remaining_time(); }
    #else
      static void __reset_remaining_time() {}
    #endif
    #if ENABLED(HAS_GCODE_PREVIEW)  
      static bool __hasPreview() { return gPreview.isValid(); }
      static void __showPreview() { gPreview.show(); }
    #else
      static bool __hasPreview() { return false;}
      static void __showPreview() { }
    #endif
  };
  extern PrintingPro printing;
#else
  class Printing {
  public:
    static void setPrintTitle(const char *text = nullptr);
    static void drawPrintProcess();
    static void drawPrintDone();
    static void hmiPrinting();
    static void printUpdate(bool force = false);
    static void doneUpdate();
  };
  extern Printing printing;
#endif


