/**
 * toolBar for PRO UI
 * Author: Miguel A. Risco-Castillo (MRISCOC)
 * version: 2.1.1
 * Date: 2023/07/12
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

#if ALL(DWIN_LCD_PROUI, HAS_TOOLBAR)

#include "dwin.h"
#include "toolbar.h"
#include "toolbar_def.h"
#include "menus.h"

const TBItem_t *TBItem;
ToolBar toolBar;

uint8_t ToolBar::OptCount() {
  return COUNT(TBItemA);
}

void onDrawTBItem(MenuItem* menuitem, int8_t line) {
  const bool focused = (checkkey == ID_Menu);
  const int8_t sel = toolBar.selected;
  const uint8_t tw = focused ? MENU_CHR_W * TBMaxCaptionWidth : 0;
  const uint8_t xoff = (DWIN_WIDTH - (B_XPOS * toolBar.count() + tw)) / 2;
  const uint8_t xp = xoff + line * B_XPOS + (line > sel ? tw : 0);
  if (focused && (line == sel)) {
    dwinDrawBox(1, COLOR_BG_WINDOW, xp - 2, TBYPOS, B_XPOS, TBHEIGHT);
    DWINUI::drawString(xp + B_XPOS, B_YPOS + 1, menuitem->caption);
  }
  DWINUI::drawIcon(menuitem->icon, xp, B_YPOS);
};

void drawToolBar(bool force /*=false*/) {
  if (force || (currentMenu != &toolBar)) {
    currentMenu = &toolBar;
    menuItemsPrepare(TBMaxOpt);
    for (uint8_t i = 0; i <= TBMaxOpt; ++i) {
      TBGetItem(PRO_data.TBopt[i]);
      if (TBItem->icon) MENU_ITEM_F(TBItem->icon, TBItem->caption, onDrawTBItem, TBItem->onClick);
    }
    toolBar.onExit = &exitToolBar;
  }
  toolBar.draw();
}

void updateTBSetupItem(MenuItem* menuitem, uint8_t val) {
  TBGetItem(val);
  menuitem->icon = TBItem->icon ?: ICON_Info;
  strcpy_P(menuitem->caption, FTOP(TBItem->caption));
}

void drawTBSetupItem(bool focused) {
  const uint8_t line = currentMenu->line();
  const uint16_t ypos = MYPOS(line) + 1;
  DWINUI::drawBox(1, focused ? COLOR_BG_BLACK : hmiData.colorBackground, { 15, ypos, DWIN_WIDTH - 15, MLINE - 1 });
  onDrawMenuItem(static_cast<MenuItem*>(currentMenu->selectedItem()), line);
  if (focused) DWINUI::drawChar(VALX + 24, MBASE(line), 18);
}

void TBGetItem(uint8_t item) {
  const uint8_t N = toolBar.OptCount() - 1;
  if (WITHIN(item, 1, N))
    TBItem = &TBItemA[item];
  else
    TBItem = &TBItemA[0];
}

#endif // ALL(DWIN_LCD_PROUI, HAS_TOOLBAR)