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

#ifndef ENGINES_NWN2_GUI_INGAME_INGAME_H
#define ENGINES_NWN2_GUI_INGAME_INGAME_H

#include <vector>
#include <memory>

#include "src/aurora/nwscript/object.h"

namespace Common {
	class UString;
}

namespace Engines {

class Console;

namespace NWN2 {

class Module;
class GUI;

/** The NWN2 ingame GUI elements. */
class IngameGUI {
public:
	IngameGUI(Module &module, ::Engines::Console *console = nullptr);
	~IngameGUI();

	void show(); ///< Show the ingame GUI elements.
	void hide(); ///< Hide the ingame GUI elements.

	void processEventQueue();

	void displayGUIScene(const Common::UString &xml, Aurora::NWScript::Object *owner);

private:
	typedef std::unique_ptr<GUI> GUIScene;
	typedef std::vector<GUIScene> GUIScenes;

	Module *_module;

	GUIScenes _guiScenes;
};

} // End of namespace NWN2

} // End of namespace Engines

#endif // ENGINES_NWN2_GUI_INGAME_INGAME_H
