/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  The NWN2 ingame GUI elements.
 */

#include "src/common/util.h"

#include "src/engines/nwn2/gui/gui.h"

#include "src/engines/nwn2/gui/ingame/ingame.h"

namespace Engines {

namespace NWN2 {

IngameGUI::IngameGUI(Module &module, ::Engines::Console *UNUSED(console)) :
	_module(&module) {

}

IngameGUI::~IngameGUI() {
	hide();
}

void IngameGUI::show() {
}

void IngameGUI::hide() {
}

void IngameGUI::processEventQueue() {
}

void IngameGUI::displayGUIScene(const Common::UString &xml, Aurora::NWScript::Object *owner) {
	_guiScenes.emplace_back(new GUI(xml, owner));
}

} // End of namespace NWN2

} // End of namespace Engines
