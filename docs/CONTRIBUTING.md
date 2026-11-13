# Contributing to scarface_decomp

Thanks for helping. This is a community project and every contribution counts, whether it is one
5-byte function, a better name or a page of notes. The goal is C++ that compiles to the game's exact
machine code, so the one thing that matters is the compiler's verdict. New here? Follow the
[quick start](../README.md#quick-start-no-experience-needed) first, and ask anything in #help on
[Discord](https://discord.gg/azvrtGBvau).

By contributing you agree to license your work under the [GPL-3.0-or-later](../LICENSE) (see
[LEGAL.md](LEGAL.md)) and to follow [PROVENANCE.md](PROVENANCE.md), which covers where code and names
may come from and how AI tools may be used.

## The usual way: the portal

1. Start the portal: double-click `START_PORTAL.bat` (Windows) or run `sh start_portal.sh`
   (macOS, Linux). It opens http://localhost:8085.
2. **Sign in** with a name and a PIN of at least 8 characters. There is no separate sign-up: the first
   time you use a name, it is created. Names are not case-sensitive. The PIN is stored only as a salted
   hash on the machine running the portal.
   That means a fresh download of the project doesn't know your PIN, and nobody can look it up. If the
   portal says your name is locked with a different PIN and you can't recall it: close the portal, rename
   `portal/private/contributor_tokens.json`, start the portal and sign in with a new PIN. Your earlier
   matches stay yours; they are in the registry under your name.
3. **Claim** a function from the queue. New here? Choose **Good first functions** above the list: small
   ones with a head start (a look-alike already matched, matched before, or named), with the reason shown.
   **Described by the specs** lists the ones whose job is already written down in `docs/cleanroom`.
   A claim is a timed lease, from 15 minutes for tiny functions to
   2 hours for large ones; only you can submit or cancel it while it lasts.
4. **Write the C++** in the editor. It starts with C++ written from the function's own machine code,
   with calls and globals already named for their addresses; for many small functions it matches as it is.
   * **decomp.me** (the backup when the compiler isn't installed or is acting up) opens the function on [decomp.me](https://decomp.me) with the same compiler
     (`msvc7.1`, platform *Windows (9x/NT)*) and our flags, filed under the [Scarface preset](https://decomp.me/preset/266).
     Its score updates as you type. Calls and
     globals show up as `_sub_XXXXXXXX` / `_DAT_XXXXXXXX`; declare them `extern "C"` with that name
     (`extern "C" int DAT_007A1234;`) and the names match. At 100%, paste the code back into the
     portal. Later clicks reopen the same scratch.
   * **AI**: you can also draft it with your own AI key. The key goes from your browser through the portal to the provider; the portal never
     stores or logs it, and the browser keeps it only for the session unless you tick "Remember key".
   * **What it does**: under the function's name, say in one plain-English line what the function does
     ("Turns the car's headlights on or off"). It is saved with your match and leads the function's page on
     the website, so people who don't read C++ can follow along. A careful guess is fine; say so. You can
     add or improve the line for any rebuilt function later: type it and press **Save**, then Submit your work.
5. **Compile & Verify** (`Ctrl+Enter`). You get the matched byte count and a per-byte diff. When it
   matches, it is recorded in `reports/verified_registry.json` under your handle and the generated
   files are rewritten. If the function has look-alikes (same machine code, other addresses; the
   queue shows "+N look-alikes"), the portal then tries your code on each of them in the background
   and credits you for every one that matches exactly. Pick those first: one match can count many times.
6. If you stop, **Cancel & Save** keeps your best partial attempt for the next person.
7. **Submit your work** when you're done for now (the red button in the sidebar; the workbench reminds you
   when you have new matches). Nothing is lost if you close the portal first: every match is saved on your
   computer the moment it verifies. Submitting packs the matches that are not on GitHub yet into one file
   (it goes to your Downloads folder); post it in #help on [Discord](https://discord.gg/azvrtGBvau) or attach
   it to a GitHub issue. A maintainer imports it, the portal compiles every function again, and each exact
   match is added under your name.

No compiler installed, or it's acting up? You can still do steps 1 to 4 with decomp.me. Post the 100% decomp.me link in a
GitHub issue or in #help on [Discord](https://discord.gg/azvrtGBvau), and a maintainer verifies it with the portal and credits you.

Maintainers (`SCARFACE_MAINTAINERS`): **Submit your work** commits and pushes the verified functions to GitHub.
It needs a folder that git knows about, made with `git clone`. To add a contributor's file, press **Import a
submission** (under it, shown to maintainers only): every function in the file is compiled again, only exact
matches are added, credited to whoever made them, and a list shows what did not match. Then press Submit your
work to push them.

**Announcing new matches on Discord** (maintainers): after each push, the portal can post the new matches,
the progress and three good first functions to a Discord channel. In Discord, open *Server Settings >
Integrations > Webhooks*, make a webhook for the channel and copy its URL; then either set the environment
variable `SCARFACE_DISCORD_WEBHOOK` to it, or save it as `portal/private/discord_webhook.txt` (that folder is
never committed). Treat the URL like a password. The first push after setting it up only notes what is
already matched; posts start with the next new match. Anyone can also follow
[`feed.xml`](https://scarface-decomp.pages.dev/feed.xml), an Atom feed of new matches, with a feed reader or a
Discord feed bot.

### Something not working?

Run this in the project folder (`python3` on macOS and Linux):

```
python portal/doctor.py
```

It checks Python, Git, your game files (and whether each is the accepted version), the compiler (with a
one-line test compile), the portal's port and whether decomp.me answers, and says how to fix each problem.
It changes nothing. Asking for help? `python portal/doctor.py --share` prints the same without your user name
or folders, ready to paste into #help on Discord. `START_PORTAL` runs a quick version every time it starts and
shows only what needs fixing.

### Updating

In a folder made with `git clone`, run `git pull`. It brings in the new code and keeps your verified
functions, claims and partial attempts (they live in `reports/`). Don't download a fresh ZIP over your
folder or replace it: anything not yet synced to GitHub would be lost. If you must, copy
`reports/verified_registry.json` out first and put it back afterwards.

### Downloaded the ZIP?

A ZIP download has no `.git` folder, so the Sync button can't push from it. To connect it once, open a
terminal (PowerShell on Windows) in the project folder and run:

```bash
git init -b main
git remote add origin https://github.com/scarface-decomp/scarface_decomp.git
git fetch origin
git reset origin/main
git branch --set-upstream-to=origin/main
```

`git reset origin/main` leaves your files exactly as they are; afterwards `git status` lists only what
you changed. Do this with a fresh download: files older than GitHub's would show up as changes.

## Without the portal

```bash
python portal/verify.py my_func.cpp --va 0x006E7EB0 --bin pc --show-diff
```

To add a function to a hand-written file in `reconstructed_src/`, declare the method with its address
in a comment and define it out of line:

```cpp
class DriveThread {
public:
    virtual void vfunc_00();   // PC VA 0x006E7EB0 (11 B)
};

void DriveThread::vfunc_00() {
    ResolveDescA(m_pDesc08);
}
```

Then run `python portal/scripts/reverify_all.py` and check `reports/reverify_report.md` before opening a
pull request. Pull requests that raise the count without the registry agreeing will not be merged.

If you change the tools, the server or the page, also run the tests (`pip install pytest playwright`):

```bash
python -m pytest -q portal/tests
```

Tests that need the compiler or the game files skip themselves when those are missing. With both in
place they include a run of the real portal on a throwaway copy of the repository.
`python portal/tools/mock_portal_api.py` serves the page with fake data for front-end work.

## Rules

* **Only the compiler decides.** No estimates, no "close enough", no counting partial matches.
* **Plain C++.** No `__asm`, `_emit`, `__declspec(naked)`, section or segment pragmas, `#pragma comment`
  or byte arrays standing in for code. The verifier rejects them.
* **No 2006 addresses as numbers.** Name globals by address instead: `extern "C" char DAT_00439DA4;`
  and `&DAT_00439DA4`. Rename them properly once you know what they are.
* **Keep the game's behaviour on `main`**, bugs included. Fixes belong in modding forks or behind a
  clearly named option.
* **US versions only.** Matches count only against the accepted files: the US Xbox disc's
  `default.xbe`, the US PC `Scarface.exe` 1.00.2 and the April 2006 prototype. Other regions, the
  unpatched PC 1.00 and edited files are refused. See [docs/GAME_VERSIONS.md](GAME_VERSIONS.md).
* **No game files, no compiler files** in commits, issues or chat: `binaries/` and `portal/tools/msvc71/`
  are ignored on purpose. CI (`portal/scripts/check_repo.py`) rejects them.
* **Bigger changes** to the tools, the verifier or the rules: open an issue first so they can be
  discussed.

## Tips for medium and large functions

Read the code generation notes in [docs/METHODOLOGY.md](METHODOLOGY.md#5-code-generation-notes-measured-with-131003052).
Most near misses come from:

* the return type (`void` vs returning a call's result changes how the stack is cleaned up);
* field types and offsets (instruction widths come from the types);
* a vtable slot that is off by one or more;
* a member call that is really a free function, or the other way round;
* a helper that the compiler inlined, such as a lock's `AddRef`.
