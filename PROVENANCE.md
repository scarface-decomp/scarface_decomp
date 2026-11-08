# Provenance

A matching decompilation is only worth something if everyone can see where it came from. These are the
rules for what may go into the repository.

## Allowed sources

* **The retail files you own**, in the accepted versions only ([docs/GAME_VERSIONS.md](docs/GAME_VERSIONS.md)):
  the US PC `Scarface.exe` 1.00.2, the US Xbox disc's `default.xbe`, and the April 2006 prototype `game.xbe`. Their machine code, RTTI type names, vtables and strings are what the project
  reconstructs.
* **Your own analysis:** disassembly, debugger sessions, notes, and names you chose because of what
  the code does.
* **Public, licensed material:** open-source libraries the game links against (with their license
  kept), public documentation and published research, credited in the pull request or commit.

## Not allowed

* Leaked, stolen or unreleased source code, debug symbols (PDB files), link maps or internal documents
  from the developer or its partners, and names or structures derived from them.
* Code copied from other decompilation projects without a compatible license and credit.
* Anything from the game files themselves other than what is needed to describe the code (no assets,
  no data dumps).

If you are unsure where something came from, leave it out and ask in an issue.

## Names

Function and class names come from RTTI in the retail binaries, from strings the code uses, or from
what the code does. A guessed name is fine; say it is a guess in a comment if it is not obvious. Names
are never taken from unreleased builds' debug data.

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
