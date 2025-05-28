/**
 * DWIN Single var plot
 * Author: Miguel A. Risco-Castillo
 * Version: 4.1.3
 * Date: 2024/06/15
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

#include "../../../inc/MarlinConfig.h"

#if ALL(DWIN_LCD_PROUI, HAS_PLOT)

#include "dwin.h"
#include "../../../core/types.h"
#include "../../marlinui.h"
#include "plot.h"

#define Plot_Bg_Color RGB( 1, 12,  8)
#define Plot_Data_Color COLOR_YELLOW
#define Plot_Ref_Color COLOR_RED

Plot plot;

uint16_t grphpoints, yref, x2, y2, xpos = 0;
frame_rect_t grphframe = {0};
float scale = 0;

uint16_t calcYpos(const_float_t value) {
  return round((y2) - value * scale);
}

void Plot::draw(const frame_rect_t &frame, const_float_t max, const_float_t ref/*=0*/) {
  grphframe = frame;
  grphpoints = 0;
  scale = frame.h / max;
  x2 = frame.x + frame.w - 1;
  y2 = frame.y + frame.h - 1;
  const uint8_t vl = frame.w / 50 + 1;
  DWINUI::drawBox(1, Plot_Bg_Color, frame);
  for (uint8_t i = 1; i < vl; i++) if (i * 50 < frame.w) dwinDrawVLine(COLOR_LINE, i * 50 + frame.x, frame.y, frame.h);
  DWINUI::drawBox(0, COLOR_WHITE, DWINUI::extendFrame(frame, 1));
  if (ref != 0) {
    yref = calcYpos(ref);
    dwinDrawHLine(Plot_Ref_Color, frame.x, yref, frame.w);
  }
  else yref = 0;
}

void Plot::update(const_float_t value) {
  if (!scale) return;
  xpos = (grphpoints < grphframe.w) ? grphpoints + grphframe.x : x2 - 1;
  const uint16_t ypos = calcYpos(value);
  if (grphpoints >= grphframe.w) {
    dwinFrameAreaMove(1, 0, 1, Plot_Bg_Color, grphframe.x, grphframe.y, x2, y2);
    if ((grphpoints % 50) == 0) dwinDrawVLine(COLOR_LINE, xpos, grphframe.y + 1, grphframe.h - 2);
    if (yref != 0) dwinDrawPoint(Plot_Ref_Color, 1, 1, xpos, yref);
  }
  dwinDrawPoint(Plot_Data_Color, 1, 1, xpos, ypos);
  grphpoints++;
}

void Plot::putPoint(const uint16_t color, const_float_t value) {
  const uint16_t ypos = calcYpos(value);
  dwinDrawPoint(color, 1, 1, xpos, ypos);
}

#endif // DWIN_LCD_PROUI && HAS_PLOT
