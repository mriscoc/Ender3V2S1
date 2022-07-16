/**
 * DWIN general defines and data structs for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 3.11.3
 * Date: 2022/02/28
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

// #define ProUIex 1
// #define HAS_GCODE_PREVIEW 1
// #define HAS_TOOLBAR 1
// #define HAS_PIDPLOT 1
// #define HAS_ESDIAG 1
// #define HAS_CGCODE 1
// #define HAS_LOCKSCREEN 1

// #define DEBUG_DWIN 1
// #define NEED_HEX_PRINT 1

#if MB(CREALITY_V24S1_301, CREALITY_V24S1_301F4)
  #define DASH_REDRAW 1
#endif

#if DISABLED(LIMITED_MAX_FR_EDITING)
  #warning "LIMITED_MAX_FR_EDITING can be enabled with ProUI."
#endif
#if DISABLED(LIMITED_MAX_ACCEL_EDITING)
  #warning "LIMITED_MAX_ACCEL_EDITING can be enabled with ProUI."
#endif
#if ENABLED(CLASSIC_JERK) && DISABLED(LIMITED_JERK_EDITING)
  #warning "LIMITED_JERK_EDITING can be enabled with ProUI."
#endif
#if DISABLED(FILAMENT_RUNOUT_SENSOR)
  #warning "FILAMENT_RUNOUT_SENSOR can be enabled with ProUI."
#endif

#if (!MB(CREALITY_V24S1_301F4) && ENABLED(AUTO_BED_LEVELING_UBL)) // Disabled for S1 F4 RCT6 for free program memory
  #if DISABLED(INDIVIDUAL_AXIS_HOMING_SUBMENU)
    #warning "INDIVIDUAL_AXIS_HOMING_SUBMENU can be enabled with ProUI."
  #endif
  #if DISABLED(LCD_SET_PROGRESS_MANUALLY)
    #warning "LCD_SET_PROGRESS_MANUALLY can be enabled with ProUI."
  #endif
  #if DISABLED(STATUS_MESSAGE_SCROLLING)
    #warning "STATUS_MESSAGE_SCROLLING can be enabled with ProUI."
  #endif
  #if DISABLED(BAUD_RATE_GCODE)
    #warning "BAUD_RATE_GCODE can be enabled with ProUI."
  #endif
  #if DISABLED(SOUND_MENU_ITEM)
    #warning "SOUND_MENU_ITEM can be enabled with ProUI."
  #endif
  #if DISABLED(PRINTCOUNTER)
    #warning "PRINTCOUNTER can be enabled with ProUI."
  #endif
#endif

#if DISABLED(MESH_EDIT_MENU)
  #warning "MESH_EDIT_MENU can be enabled with ProUI."
#endif
#if ENABLED(HAS_GCODE_PREVIEW) && DISABLED(ProUIex)
  #error "HAS_GCODE_PREVIEW requires ProUIex."
#endif
#if ENABLED(HAS_TOOLBAR) && DISABLED(ProUIex)
  #error "HAS_TOOLBAR requires ProUIex."
#endif
#if ENABLED(HAS_PIDPLOT) && DISABLED(ProUIex)
  #error "HAS_PIDPLOT requires ProUIex."
#endif

#define Def_Background_Color  RGB( 1, 12,  8)
#define Def_Cursor_color      RGB(20, 49, 31)
#define Def_TitleBg_color     RGB( 0, 23, 16)
#define Def_TitleTxt_color    Color_White
#define Def_Text_Color        Color_White
#define Def_Selected_Color    Select_Color
#define Def_SplitLine_Color   RGB( 0, 23, 16)
#define Def_Highlight_Color   Color_White
#define Def_StatusBg_Color    RGB( 0, 23, 16)
#define Def_StatusTxt_Color   Color_Yellow
#define Def_PopupBg_color     Color_Bg_Window
#define Def_PopupTxt_Color    Popup_Text_Color
#define Def_AlertBg_Color     Color_Bg_Red
#define Def_AlertTxt_Color    Color_Yellow
#define Def_PercentTxt_Color  Percent_Color
#define Def_Barfill_Color     BarFill_Color
#define Def_Indicator_Color   Color_White
#define Def_Coordinate_Color  Color_White
#define Def_Button_Color      RGB( 0, 23, 16)
#if BOTH(LED_CONTROL_MENU, HAS_COLOR_LEDS)
  #define Def_Leds_Color      0xFFFFFFFF
#endif
#if ENABLED(CASELIGHT_USES_BRIGHTNESS)
  #define Def_CaseLight_Brightness 255
#endif

#include <stddef.h>
#include "../../../core/types.h"
#include "../common/dwin_color.h"

typedef struct {
  // Color settings
  uint16_t Background_Color = Def_Background_Color;
  uint16_t Cursor_color = Def_Cursor_color;
  uint16_t TitleBg_color = Def_TitleBg_color;
  uint16_t TitleTxt_color = Def_TitleTxt_color;
  uint16_t Text_Color = Def_Text_Color;
  uint16_t Selected_Color = Def_Selected_Color;
  uint16_t SplitLine_Color = Def_SplitLine_Color;
  uint16_t Highlight_Color = Def_Highlight_Color;
  uint16_t StatusBg_Color = Def_StatusBg_Color;
  uint16_t StatusTxt_Color = Def_StatusTxt_Color;
  uint16_t PopupBg_color = Def_PopupBg_color;
  uint16_t PopupTxt_Color = Def_PopupTxt_Color;
  uint16_t AlertBg_Color = Def_AlertBg_Color;
  uint16_t AlertTxt_Color = Def_AlertTxt_Color;
  uint16_t PercentTxt_Color = Def_PercentTxt_Color;
  uint16_t Barfill_Color = Def_Barfill_Color;
  uint16_t Indicator_Color = Def_Indicator_Color;
  uint16_t Coordinate_Color = Def_Coordinate_Color;
  // Temperatures
  #if HAS_HOTEND && defined(PREHEAT_1_TEMP_HOTEND)
    int16_t HotendPidT = PREHEAT_1_TEMP_HOTEND;
  #endif
  #if defined(PREHEAT_1_TEMP_BED)
    int16_t BedPidT = PREHEAT_1_TEMP_BED;
  #endif
  #if HAS_HOTEND || HAS_HEATED_BED
    int16_t PidCycles = 10;
  #endif
  #if ENABLED(PREVENT_COLD_EXTRUSION)
    int16_t ExtMinT = EXTRUDE_MINTEMP;
  #endif
  int16_t BedLevT = LEVELING_BED_TEMP;
  TERN_(BAUD_RATE_GCODE, bool Baud115K = false);
  bool FullManualTramming = false;
  // Led
  #if ENABLED(MESH_BED_LEVELING)
    float ManualZOffset = 0;
  #endif
  #if BOTH(LED_CONTROL_MENU, HAS_COLOR_LEDS)
    uint32_t LED_Color = Def_Leds_Color;
  #endif
} HMI_data_t;

extern HMI_data_t HMI_data;

#if ProUIex

  #if HAS_TOOLBAR
    #define TBOptCount 12                 // Total of assignable functions
    #define TBMaxOpt 5                    // Amount of shortcuts on screen
    #if HAS_BED_PROBE
      #define DEF_TBOPT {0, 1, 2, 3, 4}   // Default shorcuts for ALB/UBL
    #else
      #define DEF_TBOPT {0, 1, 4, 5, 6};  // Default shortcuts for MM
    #endif
  #endif

  #include "proui.h"

  #undef X_BED_SIZE
  #undef Y_BED_SIZE
  #undef X_MIN_POS
  #undef Y_MIN_POS
  #undef X_MAX_POS
  #undef Y_MAX_POS
  #undef Z_MAX_POS
  #undef NOZZLE_PARK_POINT
  #if HAS_MESH
    #undef GRID_MAX_POINTS_X
    #undef GRID_MAX_POINTS_Y
    #undef GRID_MAX_POINTS
    #undef MESH_MIN_X
    #undef MESH_MAX_X
    #undef MESH_MIN_Y
    #undef MESH_MAX_Y
  #endif
  #if HAS_BED_PROBE
    #undef Z_PROBE_FEEDRATE_SLOW
  #endif
  #undef INVERT_E0_DIR

  #define X_BED_SIZE (float)PRO_data.x_bed_size
  #define Y_BED_SIZE (float)PRO_data.y_bed_size
  #define X_MIN_POS  (float)PRO_data.x_min_pos
  #define Y_MIN_POS  (float)PRO_data.y_min_pos
  #define X_MAX_POS  (float)PRO_data.x_max_pos
  #define Y_MAX_POS  (float)PRO_data.y_max_pos
  #define Z_MAX_POS  (float)PRO_data.z_max_pos
  #define NOZZLE_PARK_POINT {(float)PRO_data.Park_point.x, (float)PRO_data.Park_point.y, (float)PRO_data.Park_point.z}
  #if HAS_MESH
    #define GRID_MAX_POINTS_X PRO_data.grid_max_points
    #define GRID_MAX_POINTS_Y PRO_data.grid_max_points
    #define GRID_MAX_POINTS (PRO_data.grid_max_points * PRO_data.grid_max_points)
    #define MESH_MIN_X PRO_data.mesh_min_x
    #define MESH_MAX_X PRO_data.mesh_max_x
    #define MESH_MIN_Y PRO_data.mesh_min_y
    #define MESH_MAX_Y PRO_data.mesh_max_y
  #endif
  #if HAS_BED_PROBE
    #define Z_PROBE_FEEDRATE_SLOW PRO_data.zprobefeedslow
  #endif
  #define INVERT_E0_DIR PRO_data.Invert_E0

#endif  // ProUIex

static constexpr size_t eeprom_data_size = sizeof(HMI_data_t) + TERN0(ProUIex, sizeof(PRO_data_t));
