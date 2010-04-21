/* eos - A reimplementation of BioWare's Aurora engine
 * Copyright (c) 2010 Sven Hesse (DrMcCoy), Matthew Hoops (clone2727)
 *
 * The Infinity, Aurora, Odyssey and Eclipse engines, Copyright (c) BioWare corp.
 * The Electron engine, Copyright (c) Obsidian Entertainment and BioWare corp.
 *
 * This file is part of eos and is distributed under the terms of
 * the GNU General Public Licence. See COPYING for more informations.
 */

/** @file engines/sonic/sonic.h
 *  Engine class handling Sonic Chronicles: The Dark Brotherhood
 */

#ifndef ENGINES_SONIC_SONIC_H
#define ENGINES_SONIC_SONIC_H

#include "aurora/types.h"

#include "engines/engine.h"
#include "engines/engineprobe.h"

namespace Common {
	class FileList;
}

namespace Sonic {

class SonicEngineProbe : public Engines::EngineProbe {
public:
	Aurora::GameID getGameID() const;

	const std::string &getGameName() const;

	bool probe(const std::string &directory, const Common::FileList &rootFiles) const;
	bool probe(Common::SeekableReadStream &stream) const;

	Engines::Engine *createEngine() const;

private:
	static const std::string kGameName;
};

extern const SonicEngineProbe kSonicEngineProbe;

class SonicEngine : public Engines::Engine {
public:
	SonicEngine();
	~SonicEngine();

	void run(const std::string &target);

private:
	std::string _romFile;

	void init();
};

} // End of namespace Sonic

#endif // ENGINES_SONIC_SONIC_H
