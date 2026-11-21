# For AI coding agents

You are helping with a matching decompilation of *Scarface: The World Is Yours* (2006). Each function of
the game is rewritten in C++ that compiles, with the game's own compiler (Visual C++ 2003), to exactly the
bytes of the original. A person owns this checkout and their copy of the game; you work for them.

A person can start you with one sentence: **"Read AGENTS.md in this repository and follow it."**

## Rules (these come first)

1. **No leaked source code.** Never read, search for or use the leaked source of this game or of other
   games on the same engine, or tools and name lists written beside it. If a file or web page looks like
   it is that, stop reading it and tell the person.
2. **No game files in the repository.** Never commit, upload or paste the game's files, or bytes of them
   beyond what `portal/agent.py packet` prints for the one function you are working on.
3. **Real C++ only.** No inline assembly, no `__declspec(naked)`, no emitted bytes, no hard-coded
   addresses. Calls and globals are written `sub_XXXXXXXX` / `DAT_XXXXXXXX` (that name is how the address
   is checked), or by a name `reports/names.json` gives that address.
4. **Don't edit what is generated.** Not `reports/verified_registry.json`, `reports/progress.json`,
   `reconstructed_src/`, `docs/functions.json`, `docs/feed.xml`, `docs/sitemap.xml`. Only the portal
   writes those.
5. **No credentials.** Don't read `portal/private/` or any token file. Don't ask for, type or store the
   person's handle PIN or API keys. Recording a match is the person's step, not yours.
6. **Don't commit, push or open pull requests** unless the person asks you to.
7. **Say what you are.** In `// tool:` put the model that wrote the code. Names you choose come from what
   the code does, a string it uses, or the game's own class information; a guessed name is worse than
   `m_Field08`. Leave stand-ins where you don't know.
8. **A match is the compiler's verdict, not yours.** Never report a function as matched unless
   `portal/agent.py check` printed `MATCH`.

## Before you start

    python portal/doctor.py          # says what is missing: game files, the compiler

If the compiler or the game's program file is missing, stop and tell the person what `doctor.py` said.
`docs/CONTRIBUTING.md` has the setup; you cannot download the game or the compiler for them.

## The loop

    python portal/agent.py next --bin xb --max-size 40     # pick one (smallest first is a good order)
    python portal/agent.py packet xb 0x00248810            # disassembly, bytes, classmates, starter file
    #   edit work/xb_00248810.cpp
    python portal/agent.py check work/xb_00248810.cpp      # compile and compare; repeat until MATCH
    #   fill in '// what:' and '// tool:' at the top of the file
    python portal/agent.py keep work/xb_00248810.cpp       # copies it to reports/to_submit/

- `check` on the untouched starter first: for many small functions it already matches.
- When the object file holds more than one function (an inline helper, `<math.h>`, `delete`), `check`
  picks the one named `sub_XXXXXXXX` for the address. A template instantiation or a compiler helper
  is picked with `--match` (part of its compiled symbol, e.g. `--match '?$_Sort@'`); a unit built
  without one of the usual flags takes `--flags` (the function's own flags, fewer of them, or
  `/arch:SSE`). `keep` writes both into the file's `// verify:` line, and recording uses them.
- `packet` prints `hint:` lines when the function's own instructions say how its source was written
  (an 8-byte-aligned local, double `sqrt()` next to SSE code); `docs/METHODOLOGY.md` section 5 explains them.
- `packet` prints up to three functions of the same class that are already matched. Use the same class
  shape, member names and style.
- When `check` says how many bytes match, read the differing offsets against the disassembly and change
  one thing at a time. `docs/METHODOLOGY.md` section 5 lists what MSVC 7.1 does that surprises people
  (who cleans the stack, branch layout, `/G6` against `/G7` on PC, thunks that have no source).
- **Give up honestly.** After about ten tries with no gain, stop on that function: leave the best version
  in `work/` with a comment at the top saying what you tried and where it is stuck, and take the next one.
  A note like that saves the next person the same hour.
- `// what:` is one plain sentence a player could understand ("Turns the car's headlights on or off").
  If you can't say what it does, say what it returns or changes, not a guess at its purpose.

## When you have a batch

Tell the person how many files are in `reports/to_submit/` and that they record them with

    python portal/scripts/submit_matches.py

(with the portal running; it asks for their handle and PIN, verifies every file again and credits them).
Then they commit and push, or press **Submit your work** in the portal. Don't do those steps for them
unless they ask.

## Making matched code readable

A matched function can be improved without changing its bytes: better member names, parameters, types.
`python portal/agent.py packet` on a matched function writes its current text to `work/`; `check` tells
you it still matches and what is left to name. Keeping a better version of a function that is already
recorded is done in the portal (open the function, paste, **Compile & Verify**), by the person.

## Other work

`docs/HELP_WANTED.md` lists everything else that is open: file formats, cutscenes in Blender, the tools
themselves. For changes to the tools, run `python -m pytest portal/tests -q` and
`python portal/scripts/check_repo.py` before you tell the person it is done.
