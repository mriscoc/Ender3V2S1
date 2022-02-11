/**
 * DWIN general defines and data structs
 * Author: Miguel A. Risco-Castillo
 * Version: 3.10.3
 * Date: 2022/02/02
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

#define ProUI 1

//#define DEBUG_DWIN 1
//#define NEED_HEX_PRINT 1

#include "../../../core/types.h"
#include "../common/dwin_color.h"

#if ProUI
  #include "proui.h"
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

#define HAS_GCODE_PREVIEW 1
#define HAS_ESDIAG 1
#ifndef INDIVIDUAL_AXIS_HOMING_SUBMENU
  #define INDIVIDUAL_AXIS_HOMING_SUBMENU
#endif
#ifndef LCD_SET_PROGRESS_MANUALLY
  #define LCD_SET_PROGRESS_MANUALLY
#endif
#ifndef STATUS_MESSAGE_SCROLLING
  #define STATUS_MESSAGE_SCROLLING
#endif
#ifndef BAUD_RATE_GCODE
  #define BAUD_RATE_GCODE
#endif
#ifndef HAS_LCD_BRIGHTNESS
  #define HAS_LCD_BRIGHTNESS 1
#endif
#define DEFAULT_LCD_BRIGHTNESS 127
#ifndef SOUND_MENU_ITEM
  #define SOUND_MENU_ITEM
#endif

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
//
  #if defined(PREHEAT_1_TEMP_HOTEND) && HAS_HOTEND
    int16_t HotendPidT = PREHEAT_1_TEMP_HOTEND;
  #endif
  #if defined(PREHEAT_1_TEMP_BED) //&& HAS_HEATED_BED
    int16_t BedPidT = PREHEAT_1_TEMP_BED;
  #endif
  #if ANY(HAS_HOTEND, HAS_HEATED_BED)
    int16_t PidCycles = 10;
  #endif
  #if ENABLED(PREVENT_COLD_EXTRUSION)
    int16_t ExtMinT = EXTRUDE_MINTEMP;
  #endif
  #if ENABLED(PREHEAT_BEFORE_LEVELING) && defined(PREHEAT_1_TEMP_BED)
    int16_t BedLevT = PREHEAT_1_TEMP_BED;
  #endif
  TERN_(BAUD_RATE_GCODE, bool Baud115K = false);
  #if PREHEAT_1_TEMP_BED
    #undef LEVELING_BED_TEMP
    #define LEVELING_BED_TEMP HMI_data.BedLevT
  #endif
  #if ProUI
    TERN_(HAS_FILAMENT_SENSOR, bool Runout_active_state = FIL_RUNOUT_STATE);
  #if ENABLED(NOZZLE_PARK_FEATURE)
    xyz_int_t Park_point = DEF_NOZZLE_PARK_POINT;
  #endif
  int16_t x_bed_size = DEF_X_BED_SIZE;
  int16_t y_bed_size = DEF_Y_BED_SIZE;
    int16_t x_min_pos = DEF_X_MIN_POS;
    int16_t y_min_pos = DEF_Y_MIN_POS;
  int16_t x_max_pos = DEF_X_MAX_POS;
  int16_t y_max_pos = DEF_Y_MAX_POS;
  int16_t z_max_pos = DEF_Z_MAX_POS;
  TERN_(HAS_MESH, uint8_t grid_max_points = DEF_GRID_MAX_POINTS);
  #if HAS_BED_PROBE
    float probing_margin = DEF_PROBING_MARGIN;
    uint16_t zprobefeedslow = DEF_Z_PROBE_FEEDRATE_SLOW;
  #endif
  bool Invert_E0 = DEF_INVERT_E0_DIR;
  bool FilamentMotionSensor = DEF_FIL_MOTION_SENSOR;
    bool FullManualTramming = false;
  #endif
} HMI_data_t;

static constexpr size_t eeprom_data_size = 96;
extern HMI_data_t HMI_data;

#if ProUI
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
#endif
#if HAS_BED_PROBE
  #undef PROBING_MARGIN
  #undef Z_PROBE_FEEDRATE_SLOW
#endif
#undef INVERT_E0_DIR

#define X_BED_SIZE (float)HMI_data.x_bed_size
#define Y_BED_SIZE (float)HMI_data.y_bed_size
  #define X_MIN_POS  (float)HMI_data.x_min_pos
  #define Y_MIN_POS  (float)HMI_data.y_min_pos
#define X_MAX_POS  (float)HMI_data.x_max_pos
#define Y_MAX_POS  (float)HMI_data.y_max_pos
#define Z_MAX_POS  (float)HMI_data.z_max_pos
#define NOZZLE_PARK_POINT {(float)HMI_data.Park_point.x, (float)HMI_data.Park_point.y, (float)HMI_data.Park_point.z}
#if HAS_MESH
  #define GRID_MAX_POINTS_X HMI_data.grid_max_points
  #define GRID_MAX_POINTS_Y HMI_data.grid_max_points
  #define GRID_MAX_POINTS (HMI_data.grid_max_points * HMI_data.grid_max_points)
#endif
#if HAS_BED_PROBE
  #define PROBING_MARGIN HMI_data.probing_margin
  #define Z_PROBE_FEEDRATE_SLOW HMI_data.zprobefeedslow
#endif
#define INVERT_E0_DIR HMI_data.Invert_E0

#endif