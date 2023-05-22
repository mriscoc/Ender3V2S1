/**
 * ToolBar for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * version: 1.4.1
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

#include "../../../inc/MarlinConfigPre.h"

#include "dwin.h"
#include "menus.h"

#define TBHEIGHT 28
#define TBYOFFSET 20
#define TBYPOS (STATUS_Y - (TBHEIGHT + 5))
#define B_YPOS (TBYPOS + 5)
#define B_XPOS 24
#define TBMaxCaptionWidth 18

typedef struct {
  uint8_t icon = 0;
  FSTR_P caption = nullptr;
  void (*onClick)() = nullptr;
} TBItem_t;
extern const TBItem_t *TBItem;
extern const TBItem_t TBItemA[];

class ToolBarClass : public MenuClass {
public:
  void onScroll(bool dir) override;
  void draw() override;
  void (*onExit)() = nullptr;
  uint8_t OptCount();
};
extern ToolBarClass ToolBar;

void onDrawTBItem(MenuItemClass* menuitem, int8_t line);
void UpdateTBSetupItem(MenuItemClass* menuitem, uint8_t val);
void DrawTBSetupItem(bool focused);
void Draw_ToolBar(bool force = false);
void TBGetItem(uint8_t item);
