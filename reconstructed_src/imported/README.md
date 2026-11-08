# Imported sweep files

These four files came from earlier bulk passes over the binaries. They are kept as the record of what
was claimed and are rechecked by `scripts/reverify_all.py` with the same rules as everything else. Only
the functions that pass are counted; the rest are listed with the reason in
`reports/reverify_report.md`.

| File | What it holds |
| :--- | :--- |
| `stage0_full_xbe_sweep.cpp` | One-line functions for small Xbox functions; many entries are only a comment |
| `stage0_pc_scarface_exe_sweep.cpp` | The same for the readable PC range |
| `Crowdsourced_PC_Patch_Verified.cpp` | Functions recorded by the old portal. Most fail the C++ policy (they used `__asm`/`_emit`) |
| `AutoSynthesized_MSVC71_Verified.cpp` | Bulk-generated methods. They have no addresses, so nothing in it can be checked or counted |

Functions that returned a 2006 address as a number were rewritten by
`scripts/name_hardcoded_addresses.py` to use address-named symbols (`extern "C" char DAT_00439DA4;`).
The verifier checks each such name against the address the game really uses.

Do not add new work here. Use the portal, or a hand-written file in `reconstructed_src/`.
