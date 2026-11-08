# Contributing to scarface_decomp

Thanks for helping. This is a community project and every contribution counts, whether it is one
5-byte function, a better name or a page of notes. The goal is C++ that compiles to the game's exact
machine code, so the one thing that matters is the compiler's verdict. New here? Follow the
[quick start](README.md#quick-start-no-experience-needed) first.

By contributing you agree to license your work under the [GPL-3.0-or-later](LICENSE) (see
[LEGAL.md](LEGAL.md)) and to follow [PROVENANCE.md](PROVENANCE.md), which covers where code and names
may come from and how AI tools may be used.

## The usual way: the portal

1. Start the portal: double-click `START_PORTAL.bat` (Windows) or run `sh start_portal.sh`
   (macOS, Linux). It opens http://localhost:8085.
2. **Sign in** with a handle and a PIN of at least 8 characters. Handles are not case-sensitive. The
   PIN is stored only as a salted hash on the machine running the portal.
3. **Claim** a function from the queue. A claim is a timed lease, from 15 minutes for tiny functions to
   2 hours for large ones; only you can submit or cancel it while it lasts.
4. **Write the C++** in the editor, on decomp.me, or draft it with your own AI key.
   * **decomp.me** opens the function on [decomp.me](https://decomp.me) with the same compiler
     (`msvc7.1`, platform *Windows (9x/NT)*) and our flags. Its score updates as you type. Calls and
     globals show up as `_sub_XXXXXXXX` / `_DAT_XXXXXXXX`; declare them `extern "C"` with that name
     (`extern "C" int DAT_007A1234;`) and the names match. At 100%, paste the code back into the
     portal. Later clicks reopen the same scratch.
   * **AI**: the key goes from your browser through the portal to the provider; the portal never
     stores or logs it, and the browser keeps it only for the session unless you tick "Remember key".
5. **Compile & Verify** (`Ctrl+Enter`). You get the matched byte count and a per-byte diff. When it
   matches, it is recorded in `reports/verified_registry.json` under your handle and the generated
   files are rewritten.
6. If you stop, **Cancel & Save** keeps your best partial attempt for the next person.

No compiler installed? You can still do steps 1 to 4 with decomp.me. Post the 100% decomp.me link in a
GitHub issue and a maintainer verifies it with the portal and credits you.

Maintainers (`SCARFACE_MAINTAINERS`) publish verified work with **Sync Verified to GitHub**.

## Without the portal

```bash
python verify.py my_func.cpp --va 0x006E7EB0 --bin pc --show-diff
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

Then run `python scripts/reverify_all.py` and check `reports/reverify_report.md` before opening a
pull request. Pull requests that raise the count without the registry agreeing will not be merged.

If you change the tools, the server or the page, also run the tests (`pip install pytest playwright`):

```bash
python -m pytest -q tests/
```

Tests that need the compiler or the game files skip themselves when those are missing. With both in
place they include a run of the real portal on a throwaway copy of the repository.
`python tools/mock_portal_api.py` serves the page with fake data for front-end work.

## Rules

* **Only the compiler decides.** No estimates, no "close enough", no counting partial matches.
* **Plain C++.** No `__asm`, `_emit`, `__declspec(naked)`, section or segment pragmas, `#pragma comment`
  or byte arrays standing in for code. The verifier rejects them.
* **No 2006 addresses as numbers.** Name globals by address instead: `extern "C" char DAT_00439DA4;`
  and `&DAT_00439DA4`. Rename them properly once you know what they are.
* **Keep the game's behaviour on `main`**, bugs included. Fixes belong in modding forks or behind a
  clearly named option.
* **No game files, no compiler files** in commits: `binaries/` and `tools/msvc71/` are ignored on
  purpose. CI (`scripts/check_repo.py`) rejects them.
* **Bigger changes** to the tools, the verifier or the rules: open an issue first so they can be
  discussed.

## Tips for medium and large functions

Read the code generation notes in [docs/METHODOLOGY.md](docs/METHODOLOGY.md#5-code-generation-notes-measured-with-131003052).
Most near misses come from:

* the return type (`void` vs returning a call's result changes how the stack is cleaned up);
* field types and offsets (instruction widths come from the types);
* a vtable slot that is off by one or more;
* a member call that is really a free function, or the other way round;
* a helper that the compiler inlined, such as a lock's `AddRef`.
