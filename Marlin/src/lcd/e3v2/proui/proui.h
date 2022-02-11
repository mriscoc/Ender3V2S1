/**
 * Professional Firmware UI extensions
 * Author: Miguel A. Risco-Castillo
 * Version: 1.0
 * Date: 2022/01/31
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
 * For commercial applications additional licences can be requested
 */
#pragma once

#include "../../../inc/MarlinConfigPre.h"

#if ANY(AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_3POINT) && DISABLED(PROBE_MANUALLY)
  #define HAS_ONESTEP_LEVELING 1
#endif

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
#define DEF_NOZZLE_PARK_POINT {240, 220, 20}
#if HAS_MESH
  constexpr int8_t DEF_GRID_MAX_POINTS = GRID_MAX_POINTS_X;
  #define GRID_LIMIT 9
#endif
#if HAS_BED_PROBE
  constexpr int16_t DEF_PROBING_MARGIN = PROBING_MARGIN;
  #define MIN_PROBE_MARGIN 10
  #define MAX_PROBE_MARGIN 60
  constexpr int16_t DEF_Z_PROBE_FEEDRATE_SLOW = (Z_PROBE_FEEDRATE_FAST / 2);
#endif
#define DEF_INVERT_E0_DIR false
#define DEF_FIL_MOTION_SENSOR false

class ProUIClass {
public:
#if HAS_ONESTEP_LEVELING
  static void HeatedBed();
  static void StopLeveling();
  static bool CompletedLeveling();
#endif
#if HAS_FILAMENT_SENSOR
  static void SetRunoutState();
  static void DrawRunoutActive(bool selected);
  static void ApplyRunoutActive();
  static void C412();
#endif
#if ENABLED(AUTO_BED_LEVELING_BILINEAR)
  static void abl_extrapolate();
#endif
#if ENABLED(POWER_LOSS_RECOVERY)
  static void PowerLoss();
#endif
#if HAS_MESH
  static void DrawMeshPoints(bool selected, int8_t line, uint8_t MeshPoints);
  static void ApplyMeshPoints();
  static void C29();
#endif
  static void C100();
  static void C101();
  static void C102();
#if ENABLED(NOZZLE_PARK_FEATURE)
  static void C125();
#endif
  static void C562();
#if HAS_BED_PROBE
  static void C851();
#endif
  static void UpdateAxis(const AxisEnum axis);
  static void ApplyPhySet();
  static void SetDefaults();
  static void LoadSettings();
};

extern ProUIClass ProEx;
