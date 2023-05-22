/**
 * DWIN Enhanced implementation for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * Version: 3.25.3
 * Date: 2023/05/18
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

#include "../../../inc/MarlinConfig.h"

#include "dwin_defines.h"
#include "dwinui.h"
#include "../common/encoder.h"
#include "../common/limits.h"
#include "../../../libs/BL24CXX.h"

#if HAS_CGCODE
  #include "custom_gcodes.h"
#endif

#if ENABLED(CV_LASER_MODULE)
  #include "cv_laser_module.h"
#endif

namespace GET_LANG(LCD_LANGUAGE) {
  #define _MSG_PREHEAT(N) \
    LSTR MSG_PREHEAT_##N                  = _UxGT("Preheat ") PREHEAT_## N ##_LABEL; \
    LSTR MSG_PREHEAT_## N ##_SETTINGS     = _UxGT("Preheat ") PREHEAT_## N ##_LABEL _UxGT(" Conf");
  #if PREHEAT_COUNT > 3
    REPEAT_S(4, PREHEAT_COUNT, _MSG_PREHEAT)
  #endif
}

extern char DateTime[16+1];

enum processID : uint8_t {
  // Process ID
  MainMenu,
  Menu,
  SetInt,
  SetPInt,
  SetIntNoDraw,
  SetFloat,
  SetPFloat,
  PrintProcess,
  Popup,
  Leveling,
  Locked,
  Reboot,
  PrintDone,
  ESDiagProcess,
  WaitResponse,
  Homing,
  PidProcess,
  MPCProcess,
  NothingToDo
};

#if HAS_PID_HEATING || ENABLED(MPC_AUTOTUNE)
  enum tempcontrol_t : uint8_t {
  #if HAS_PID_HEATING
    PIDTEMP_START = 0,
    PIDTEMPBED_START,
    PID_BAD_HEATER_ID,
    PID_TEMP_TOO_HIGH,
    PID_TUNING_TIMEOUT,
  #endif
  #if ENABLED(MPC_AUTOTUNE)
    MPCTEMP_START,
    MPC_TEMP_ERROR,
    MPC_INTERRUPTED,
  #endif
  AUTOTUNE_DONE
  };
#endif

#define DWIN_CHINESE 123
#define DWIN_ENGLISH 0

typedef struct {
  uint16_t Background_Color;
  uint16_t Cursor_Color;
  uint16_t TitleBg_Color;
  uint16_t TitleTxt_Color;
  uint16_t Text_Color;
  uint16_t Selected_Color;
  uint16_t SplitLine_Color;
  uint16_t Highlight_Color;
  uint16_t StatusBg_Color;
  uint16_t StatusTxt_Color;
  uint16_t PopupBg_Color;
  uint16_t PopupTxt_Color;
  uint16_t AlertBg_Color;
  uint16_t AlertTxt_Color;
  uint16_t PercentTxt_Color;
  uint16_t Barfill_Color;
  uint16_t Indicator_Color;
  uint16_t Coordinate_Color;
  int16_t HotendPidT;
  int16_t BedPidT;
  int16_t PidCycles;
  int16_t ExtMinT;
  int16_t BedLevT;
  bool Baud115K;
  bool FullManualTramming;
  bool MediaSort;
  bool MediaAutoMount;
  uint8_t z_after_homing;
  float ManualZOffset;
  uint32_t Led_Color;
  bool AdaptiveStepSmoothing;
  bool EnablePreview;
} HMI_data_t;

extern HMI_data_t HMI_data;
static constexpr size_t eeprom_data_size = sizeof(HMI_data_t) + TERN0(PROUI_EX, sizeof(PRO_data_t));

typedef struct {
  int8_t Color[3];                    // Color components
  #if ANY(HAS_PID_HEATING, MPCTEMP)
    tempcontrol_t tempcontrol = AUTOTUNE_DONE;
  #endif
  uint8_t Select          = 0;        // Auxiliary selector variable
  AxisEnum axis           = X_AXIS;   // Axis Select
} HMI_value_t;

typedef struct {
  bool printing_flag:1; // sd or host printing
  bool abort_flag:1;    // sd or host was aborted
  bool pause_flag:1;    // printing is paused
  bool select_flag:1;   // Popup button selected
  bool home_flag:1;     // homing in course
  bool config_flag:1;   // SD G-code file is a Configuration file
  #if PROUI_EX && HAS_LEVELING
    bool cancel_abl:1;  // cancel current abl
  #endif
} HMI_flag_t;

extern HMI_value_t HMI_value;
extern HMI_flag_t HMI_flag;
extern uint8_t checkkey;

// Popups
#if HAS_HOTEND || HAS_HEATED_BED
  void DWIN_Popup_Temperature(const int_fast8_t heater_id, const bool toohigh);
#endif
#if ENABLED(POWER_LOSS_RECOVERY)
  void Popup_PowerLossRecovery();
#endif

// Tool Functions
uint32_t GetHash(char * str);
#if ENABLED(EEPROM_SETTINGS)
  void WriteEeprom();
  void ReadEeprom();
  void ResetEeprom();
  #if HAS_MESH
    void SaveMesh();
  #endif
#endif
void RebootPrinter();
void DisableMotors();
void AutoLev();
void AutoHome();
#if HAS_PREHEAT
  #define _DOPREHEAT(N) void DoPreheat##N();
  REPEAT_1(PREHEAT_COUNT, _DOPREHEAT)
#endif
void DoCoolDown();
#if ENABLED(BAUD_RATE_GCODE)
  void SetBaud115K();
  void SetBaud250K();
#endif
#if HAS_LCD_BRIGHTNESS
  void TurnOffBacklight();
#endif
void ApplyExtMinT();
void ParkHead();
#if ENABLED(LCD_BED_TRAMMING)
  TERN(HAS_BED_PROBE, float, void) Tram(uint8_t point, bool stow_probe = true);
  #if ENABLED(HAS_BED_PROBE)
    void Trammingwizard();
  #endif
#endif
#if BOTH(LED_CONTROL_MENU, HAS_COLOR_LEDS)
  void ApplyLEDColor();
#endif
#if ENABLED(AUTO_BED_LEVELING_UBL)
  void UBLMeshTilt();
  void UBLMeshSave();
  void UBLMeshLoad();
#endif
#if ENABLED(HOST_SHUTDOWN_MENU_ITEM) && defined(SHUTDOWN_ACTION)
  void HostShutDown();
#endif
#if DISABLED(HAS_BED_PROBE)
  void HomeZandDisable();
#endif

// Other
void Goto_PrintProcess();
void Goto_Main_Menu();
void Goto_Info_Menu();
void Goto_PowerLossRecovery();
void Goto_ConfirmToPrint();
void Draw_Main_Area();      // Redraw main area
void DWIN_DrawStatusLine(const char *text = ""); // Draw simple status text
void DWIN_RedrawDash();     // Redraw Dash and Status line
void DWIN_RedrawScreen();   // Redraw all screen elements
void HMI_MainMenu();        // Main process screen
void HMI_Printing();        // Print page
void HMI_ReturnScreen();    // Return to previous screen before popups
void HMI_WaitForUser();
void HMI_SaveProcessID(const uint8_t id);
void HMI_SDCardUpdate();
void EachMomentUpdate();
void update_variable();
void DWIN_InitScreen();
void DWIN_HandleScreen();
void DWIN_CheckStatusMessage();
void DWIN_HomingStart();
void DWIN_HomingDone();
#if HAS_MESH
  void DWIN_MeshUpdate(const int8_t cpos, const int8_t tpos, const_float_t zval);
#endif
void DWIN_LevelingStart();
void DWIN_LevelingDone();
void DWIN_Print_Started();
void DWIN_Print_Pause();
void DWIN_Print_Resume();
void DWIN_Print_Finished();
void DWIN_Print_Aborted();
#if HAS_FILAMENT_SENSOR
  void DWIN_FilamentRunout(const uint8_t extruder);
#endif
void DWIN_Print_Header(const char *text);
void DWIN_SetColorDefaults();
void DWIN_CopySettingsTo(char * const buff);
void DWIN_CopySettingsFrom(const char * const buff);
void DWIN_SetDataDefaults();
void DWIN_RebootScreen();
inline void DWIN_Gcode(const int16_t codenum) { TERN_(HAS_CGCODE, custom_gcode(codenum)); };

#if ENABLED(ADVANCED_PAUSE_FEATURE)
  void DWIN_Popup_Pause(FSTR_P const fmsg, uint8_t button=0);
  void Draw_Popup_FilamentPurge();
  void Goto_FilamentPurge();
#endif

// Utility and extensions
#if HAS_LOCKSCREEN
  void DWIN_LockScreen();
  void DWIN_UnLockScreen();
  void HMI_LockScreen();
#endif
#if HAS_MESH
  void DWIN_MeshViewer();
#endif
#if HAS_ESDIAG
  void Draw_EndStopDiag();
#endif

// Menu drawing functions
void Draw_Print_File_Menu();
void Draw_Control_Menu();
void Draw_AdvancedSettings_Menu();
void Draw_Prepare_Menu();
void Draw_Move_Menu();
void Draw_Tramming_Menu();
#if HAS_HOME_OFFSET
  void Draw_HomeOffset_Menu();
#endif
#if HAS_BED_PROBE
  void Draw_ProbeSet_Menu();
#endif
void Draw_FilSet_Menu();
#if ENABLED(NOZZLE_PARK_FEATURE)
  void Draw_ParkPos_Menu();
#endif
void Draw_PhySet_Menu();
#if BOTH(CASE_LIGHT_MENU, CASELIGHT_USES_BRIGHTNESS)
  void Draw_CaseLight_Menu();
#endif
#if ENABLED(LED_CONTROL_MENU)
  void Draw_LedControl_Menu();
#endif
void Draw_Tune_Menu();
void Draw_Motion_Menu();
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  void Draw_FilamentMan_Menu();
#endif
#if ENABLED(MESH_BED_LEVELING)
  void Draw_ManualMesh_Menu();
#endif
void Draw_Temperature_Menu();
void Draw_MaxSpeed_Menu();
void Draw_MaxAccel_Menu();
#if HAS_CLASSIC_JERK
  void Draw_MaxJerk_Menu();
#endif
void Draw_Steps_Menu();
#if EITHER(HAS_BED_PROBE, BABYSTEPPING)
  void Draw_ZOffsetWiz_Menu();
#endif
#if ENABLED(INDIVIDUAL_AXIS_HOMING_SUBMENU)
  void Draw_Homing_Menu();
#endif
#if ENABLED(FWRETRACT)
  void Draw_FWRetract_Menu();
#endif
#if HAS_MESH
  void Draw_MeshSet_Menu();
  void Draw_MeshInset_Menu();
  #if ENABLED(MESH_EDIT_MENU)
    void Draw_EditMesh_Menu();
  #endif
#endif
#if HAS_TRINAMIC_CONFIG
  void Draw_TrinamicConfig_menu();
#endif

// Custom colors editing
#if HAS_CUSTOM_COLORS
  void DWIN_ApplyColor();
  void DWIN_ApplyColor(const int8_t element, const bool ldef=false);
  void Draw_SelectColors_Menu();
  void Draw_GetColor_Menu();
#endif

// PID
#if HAS_PID_HEATING
  #include "../../../module/temperature.h"
  void DWIN_M303(const bool seenC, const int c, const bool seenS, const heater_id_t hid, const celsius_t temp);
  void DWIN_PidTuning(tempcontrol_t result);
#endif
#if ENABLED(PIDTEMP)
  #if ENABLED(PID_AUTOTUNE_MENU)
    void HotendPID();
  #endif
  #if EITHER(PID_AUTOTUNE_MENU, PID_EDIT_MENU)
    void Draw_HotendPID_Menu();
  #endif
#endif
#if ENABLED(PIDTEMPBED)
  #if ENABLED(PID_AUTOTUNE_MENU)
    void BedPID();
  #endif
  #if EITHER(PID_AUTOTUNE_MENU, PID_EDIT_MENU)
    void Draw_BedPID_Menu();
  #endif
#endif

// MPC
#if EITHER(MPC_EDIT_MENU, MPC_AUTOTUNE_MENU)
  void Draw_HotendMPC_Menu();
#endif
#if ENABLED(MPC_AUTOTUNE)
  void DWIN_MPCTuning(tempcontrol_t result);
#endif

// CV Laser Module
#if ENABLED(CV_LASER_MODULE)
  void LaserOn(const bool turn_on);
  void Draw_LaserSettings_Menu();
  void Draw_LaserPrint_Menu();
#endif

// ToolBar
#if HAS_TOOLBAR
  void Draw_TBSetup_Menu();
  void Goto_ToolBar();
  void Exit_ToolBar();
#endif

#if DEBUG_DWIN
  void DWIN_Debug(const char *msg);
#endif
