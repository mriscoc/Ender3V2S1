/**
 * Professional Firmware UI extensions
 * Author: Miguel A. Risco-Castillo
 * Version: 1.10.0
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
 * For commercial applications additional licenses can be requested
 */
#pragma once

#include "../../../inc/MarlinConfigPre.h"

#ifndef LOW
  #define LOW  0x0
#endif
#ifndef HIGH
  #define HIGH 0x1
#endif

#define X_BED_MIN 150
#define Y_BED_MIN 150
constexpr int16_t DEF_X_BED_SIZE = X_BED_SIZE;
constexpr int16_t DEF_Y_BED_SIZE = Y_BED_SIZE;
constexpr int16_t DEF_X_MIN_POS = X_MIN_POS;
constexpr int16_t DEF_Y_MIN_POS = Y_MIN_POS;
constexpr int16_t DEF_X_MAX_POS = X_MAX_POS;
constexpr int16_t DEF_Y_MAX_POS = Y_MAX_POS;
constexpr int16_t DEF_Z_MAX_POS = Z_MAX_POS;
constexpr bool DEF_INVERT_E0_DIR = INVERT_E0_DIR;
#if ENABLED(NOZZLE_PARK_FEATURE)
  constexpr xyz_int_t DEF_NOZZLE_PARK_POINT = NOZZLE_PARK_POINT;
#else
  constexpr xyz_int_t DEF_NOZZLE_PARK_POINT = {0};
#endif
constexpr int8_t DEF_GRID_MAX_POINTS = TERN(HAS_MESH, GRID_MAX_POINTS_X, 3);
#define GRID_MIN 3
#define GRID_LIMIT 9
#ifndef MESH_INSET
  #define MESH_INSET 25
#endif
#ifndef MESH_MIN_X
  #define MESH_MIN_X MESH_INSET
#endif
#ifndef MESH_MIN_Y
  #define MESH_MIN_Y MESH_INSET
#endif
#ifndef MESH_MAX_X
  #define MESH_MAX_X  X_BED_SIZE - (MESH_INSET)
#endif
#ifndef MESH_MAX_Y
  #define MESH_MAX_Y  Y_BED_SIZE - (MESH_INSET)
#endif
constexpr int16_t DEF_MESH_MIN_X = MESH_MIN_X;
constexpr int16_t DEF_MESH_MAX_X = MESH_MAX_X;
constexpr int16_t DEF_MESH_MIN_Y = MESH_MIN_Y;
constexpr int16_t DEF_MESH_MAX_Y = MESH_MAX_Y;
#define MIN_MESH_INSET TERN(HAS_BED_PROBE, PROBING_MARGIN, 5)
#define MAX_MESH_INSET X_BED_SIZE
constexpr int16_t DEF_PROBING_MARGIN = PROBING_MARGIN;
#define MIN_PROBE_MARGIN 5
#define MAX_PROBE_MARGIN 60
constexpr int16_t DEF_Z_PROBE_FEEDRATE_SLOW = (Z_PROBE_FEEDRATE_FAST / 2);
#ifndef MULTIPLE_PROBING
  #define MULTIPLE_PROBING 0
#endif
#define DEF_FIL_MOTION_SENSOR ENABLED(FILAMENT_MOTION_SENSOR)
#if DISABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_STATE LOW
#endif

typedef struct {
  int16_t x_bed_size = DEF_X_BED_SIZE;
  int16_t y_bed_size = DEF_Y_BED_SIZE;
  int16_t x_min_pos  = DEF_X_MIN_POS;
  int16_t y_min_pos  = DEF_Y_MIN_POS;
  int16_t x_max_pos  = DEF_X_MAX_POS;
  int16_t y_max_pos  = DEF_Y_MAX_POS;
  int16_t z_max_pos  = DEF_Z_MAX_POS;
  uint8_t grid_max_points = DEF_GRID_MAX_POINTS;
  float mesh_min_x = DEF_MESH_MIN_X;
  float mesh_max_x = DEF_MESH_MAX_X;
  float mesh_min_y = DEF_MESH_MIN_Y;
  float mesh_max_y = DEF_MESH_MAX_Y;
  uint16_t zprobefeedslow = DEF_Z_PROBE_FEEDRATE_SLOW;
  uint8_t multiple_probing = MULTIPLE_PROBING;
  bool Invert_E0 = DEF_INVERT_E0_DIR;
  xyz_int_t Park_point = DEF_NOZZLE_PARK_POINT;
  bool Runout_active_state = FIL_RUNOUT_STATE;
  bool FilamentMotionSensor = DEF_FIL_MOTION_SENSOR;
  celsius_t hotend_maxtemp = HEATER_0_MAXTEMP;
  uint8_t TBopt[TBMaxOpt] = DEF_TBOPT;
} PRO_data_t;
extern PRO_data_t PRO_data;

class ProUIClass {
public:
  static void Init();
#if HAS_BED_PROBE
  static void HeatedBed();
  static void StopLeveling();
  static bool QuitLeveling();
  static void MeshUpdate(const int8_t x, const int8_t y, const_float_t zval);
  static void LevelingDone();
#endif
#if HAS_MEDIA
  static void C10();
#endif
#if HAS_FILAMENT_SENSOR
  static void SetRunoutState(uint32_t ulPin);
  static void DrawRunoutActive(bool selected);
  static void ApplyRunoutActive();
  static void C412();
  static void C412_report(const bool forReplay=true);
#endif
#if HAS_MESH
  static void DrawMeshPoints(bool selected, int8_t line, uint8_t MeshPoints);
  static void CheckMeshInsets();
  static void ApplyMeshLimits();
  static void ApplyMeshPoints();
  static void C29();
  static void C29_report(const bool forReplay=true);
#endif
  static void C100();
  static void C100_report(const bool forReplay=true);
  static void C101();
  static void C101_report(const bool forReplay=true);
  static void C102();
  static void C102_report(const bool forReplay=true);
  static void C104();
  static void C104_report(const bool forReplay=true);
  static void C115();
#if ENABLED(NOZZLE_PARK_FEATURE)
  static void C125();
  static void C125_report(const bool forReplay=true);
#endif
#if HAS_EXTRUDERS
  static void C562();
  static void C562_report(const bool forReplay=true);
#endif
  static void C851();
  static void C851_report(const bool forReplay=true);
#if HAS_TOOLBAR
  static void C810();
  static void C810_report(const bool forReplay=true);
#endif
  static void UpdateAxis(const AxisEnum axis);
  static void ApplyPhySet();
  static void CheckParkingPos();
  static void SetData();
  static void LoadSettings();
  #if EITHER(AUTO_BED_LEVELING_BILINEAR, MESH_BED_LEVELING)
    static float getZvalues(const uint8_t sy, const uint8_t x, const uint8_t y, const float *values);
  #endif
};

extern ProUIClass ProEx;
