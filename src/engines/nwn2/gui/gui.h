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
 *  A NWN2 GUI.
 */

#ifndef ENGINES_NWN2_GUI_GUI_H
#define ENGINES_NWN2_GUI_GUI_H

#include "src/aurora/types.h"

#include "src/graphics/aurora/types.h"

#include "src/engines/aurora/gui.h"

namespace Aurora {
	namespace NWScript {
		class Object;
	}
}

namespace Engines {

namespace NWN2 {

/** A NWN2 GUI. */
class GUI : public ::Engines::GUI {
public:
	GUI(const Common::UString &xml, Aurora::NWScript::Object *owner, ::Engines::Console *console = 0);
	~GUI() = default;

private:
	const Common::UString _xml;

	Aurora::NWScript::Object *_owner;

	void load();
};

} // End of namespace NWN2

} // End of namespace Engines

#endif // ENGINES_NWN2_GUI_GUI_H
