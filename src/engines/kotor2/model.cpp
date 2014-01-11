/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names can be
 * found in the AUTHORS file distributed with this source
 * distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 *
 * The Infinity, Aurora, Odyssey, Eclipse and Lycium engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 */

/** @file engines/kotor2/model.cpp
 *  Utility functions for Star Wars: Knights of the Old Republic II - The Sith Lords models.
 */

#include "common/maths.h"

#include "graphics/aurora/sceneman.h"
#include "graphics/aurora/model_kotor.h"

#include "engines/kotor2/model.h"

namespace Engines {

namespace KotOR2 {

Graphics::Aurora::Model_KotOR *createWorldModel(const Common::UString &model, const Common::UString &texture) {
	Graphics::Aurora::Model_KotOR *modelInstance = (Graphics::Aurora::Model_KotOR *) SceneMan.createModel(model, texture);

	modelInstance->setBaseOrientation(Common::deg2rad(-90.0), 1.0, 0.0, 0.0);

	return modelInstance;
}

void destroyModel(Graphics::Aurora::Model_KotOR *model) {
	SceneMan.destroy(model);
}

} // End of namespace KotOR2

} // End of namespace Engines
