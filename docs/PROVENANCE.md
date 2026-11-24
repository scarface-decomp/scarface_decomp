# Provenance

A matching decompilation is only worth something if everyone can see where it came from. These are the
rules for what may go into the repository.

## Allowed sources

* **The retail files you own**, in the accepted versions only ([docs/GAME_VERSIONS.md](GAME_VERSIONS.md)):
  the US PC `Scarface.exe` 1.00.2, the US Xbox disc's `default.xbe`, the US PS2 disc's `SLUS_211.11`, and the April 2006 prototype `game.xbe`. Their machine code, RTTI type names, vtables and strings are what the project
  reconstructs.
* **Your own analysis:** disassembly, debugger sessions, notes, and names you chose because of what
  the code does.
* **Public, licensed material:** open-source libraries the game links against (with their license
  kept), public documentation and published research, credited in the pull request or commit.
* **Two prototype builds' linker maps, for names only:** the builds, and what may be taken from each, are
  listed in [CLEAN_ROOM.md](CLEAN_ROOM.md#names-from-another-games-build). The map files stay out of the
  repository. Another build's map may be used only after the founder adds it to that list.

## Not allowed in the repository

* Leaked, stolen or unreleased source code, debug symbols (PDB files) or internal documents from the
  developer or its partners, and code, names or structures taken from them.
* Link maps from the developer or its partners, as files, and names from any map other than the ones
  listed in CLEAN_ROOM.md.
* Code copied from other decompilation projects without a compatible license and credit.
* Anything from the game files themselves other than what is needed to describe the code (no assets,
  no data dumps).

If you are unsure where something came from, leave it out and ask in an issue.

## Studying material that can't come in: the clean room

Material that can't come into the repository may still be studied, whatever it is: leaked source, debug
symbols, other builds, and research that was done with them at hand. Its code and names stay out of the
project. What it shows about the game's files and behaviour may come in only through the clean-room
process in [CLEAN_ROOM.md](CLEAN_ROOM.md): someone who read it (the examiner) writes a spec in their own
words (no code, no names from it), with every statement something that can be checked on a copy of the
game; the spec is reviewed; and someone who has never read the material writes the code from the spec and
the game files. Whoever has read such material doesn't write code for what it covers, and never supplies
or confirms a name from it. The record of who read what is kept in CLEAN_ROOM.md.

## Names

Function and class names come from RTTI in the retail binaries, from strings the code uses (the names
the game registers its script commands under among them), or from what the code does. A name another
project published under a licence that allows it may be used when it is checked against the code and the
project is named as its source (`by` in `reports/names.json`, and in [CREDITS.md](CREDITS.md)). A guessed name is fine; say it is a guess in a comment if it is not obvious. Names
are never taken from leaked source or debug symbols. The only names from other games' builds are those
from the linker maps listed in [CLEAN_ROOM.md](CLEAN_ROOM.md#names-from-another-games-build).

## AI tools

AI assistants may be used to draft code, and the portal can call your own AI key. The rules are the
same as for anyone else:

* **The compiler decides.** A function counts only when the verifier says `VERIFIED`: exact length and
  bytes, checked relocations, no hard-coded addresses, plain C++. A model saying it matches means
  nothing.
* **A person is responsible.** Whoever submits the code is its author and answers for it: it must make
  sense, have reasonable names, and follow these provenance rules.
* **Say so.** The portal records the tool used with each verified function (`tool_used` in
  `reports/verified_registry.json`). In pull requests, mention when code or comments were generated.
* **No bulk dumps.** Large generated batches go through the same checks and review as everything else,
  in reviewable pieces.
* Comments and names written by a model can be wrong; the machine code is the authority.
