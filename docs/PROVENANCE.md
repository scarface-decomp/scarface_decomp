# Provenance

A matching decompilation is only worth something if everyone can see where it came from. These are the
rules for what may go into the repository.

**The short version.** Anything you hold your own copy of, you may study and use: the game, its other
builds, other games, development kits and their manuals. What you learn from it may come in; the files
themselves stay out. The one thing kept behind a wall is leaked source code and leaked symbol files,
which were never on any disc.

## Allowed sources

* **The retail files you own**, in the accepted versions only ([docs/GAME_VERSIONS.md](GAME_VERSIONS.md)):
  the US PC `Scarface.exe` 1.00.2, the US Xbox disc's `default.xbe`, the US PS2 disc's `SLUS_211.11`, and the April 2006 prototype `game.xbe`. Their machine code, RTTI type names, vtables and strings are what the project
  reconstructs.
* **Your own analysis:** disassembly, debugger sessions, notes, and names you chose because of what
  the code does.
* **Public, licensed material:** open-source libraries the game links against (with their license
  kept), public documentation and published research, credited in the pull request or commit.
* **Published tools and research about the game,** including work whose author had leaked source at
  hand (*scarface-p3d*, the ToolKit). Anyone may read them. What they say counts only where the game
  agrees; they are credited in [CREDITS.md](CREDITS.md); code is copied only where its licence allows,
  with the licence kept (a project with no licence may be learned from, not copied).
* **Other discs and kits you hold your own copy of:** prototype, review and retail builds of this game
  or another one, and development kits with their libraries and manuals. Whatever such a disc or kit
  carries may be read and used by whoever holds it: its programs, the type names and text inside them,
  and a linker map or symbol table the build itself put on the disc. This is open to every contributor,
  not only the founder. Three conditions:
  * **Check it against Scarface.** A name or a fact from another build counts only where Scarface's own
    code agrees with it; the verifier still decides every function.
  * **Record it.** The build, the file and what was taken are listed in
    [CLEAN_ROOM.md](CLEAN_ROOM.md#other-builds-the-project-reads). Add a row in the same pull request.
  * **Keep the files out.** Nothing from the disc or kit is uploaded here or anywhere else in the
    project (issues, chat): no programs, maps, libraries or disc images. Contribute what you learned.

## Not allowed in the repository

* Leaked or stolen source code, leaked symbol files (PDB files and the like) and internal documents
  from the developer or its partners, and code, names or structures taken from them. The test: was it
  on a disc or in a kit that its owner made and handed out, or is it the developer's own working files
  that got out? Only the second kind is kept out.
* Files from any disc or kit, as files: programs, link maps, libraries, disc images.
* Code copied from other decompilation projects without a compatible license and credit.
* Anything from the game files themselves other than what is needed to describe the code (no assets,
  no data dumps).

If you are unsure where something came from, leave it out and ask in an issue.

## Studying leaked material: the clean room

Leaked source and leaked symbol files may still be studied. Their code and names stay out of the
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
are never taken from leaked source or leaked symbol files. A name from another build's own files (a
linker map or symbol table on a disc someone holds) may be used when Scarface's code agrees with it and
the build is recorded in [CLEAN_ROOM.md](CLEAN_ROOM.md#other-builds-the-project-reads).

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
