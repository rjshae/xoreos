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

#include <memory>

#include "src/common/xml.h"

#include "src/aurora/types.h"
#include "src/aurora/resman.h"
#include "src/aurora/xmlfixer.h"

#include "src/engines/nwn2/gui/gui.h"

namespace Engines {

namespace NWN2 {

GUI::GUI(const Common::UString &xml, Aurora::NWScript::Object *owner, ::Engines::Console *console) :
	::Engines::GUI(console), _xml(xml), _owner(owner) {

	load();
}

void GUI::load() {
	// Load XML resource file into memory
	std::unique_ptr<Common::SeekableReadStream> stream(ResMan.getResource(_xml, Aurora::kFileTypeXML));
	if (!stream)
		throw Common::Exception("Can't load XML resource file \"%s\" for GUI", _xml.c_str());

	// Fix broken, non-standard NWN2 XML
	std::unique_ptr<Common::SeekableReadStream> fixed(Aurora::XMLFixer::fixXMLStream(*stream));
	if (!fixed)
		throw Common::Exception("Can't convert \"%s\" XML resource file to standard XML", _xml.c_str());

	// Parse the repaired XML
	std::unique_ptr<Common::XMLParser> parser(new Common::XMLParser(*fixed));
	if (!parser)
		throw Common::Exception("Can't parse fixed \"%s\" XML file", _xml.c_str());
}

} // End of namespace NWN2

} // End of namespace Engines
