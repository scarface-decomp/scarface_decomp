## What this changes

<!-- e.g. "Matches EmpireHUD::OnPageInit (xb 0x00194050, 23 B)" or "Names the Stats class fields" -->

## Checklist

- [ ] `python portal/scripts/reverify_all.py` ran, and `reports/reverify_report.md` shows the functions I claim as `VERIFIED`
- [ ] `python -m pytest -q tests` passes (if I changed tools, the server or the page)
- [ ] Plain C++ only: no inline assembly, `_emit`, `naked` functions, section pragmas, or numbers standing in for 2006 addresses
- [ ] Everything follows docs/PROVENANCE.md: no leaked source or PDBs, and no names from other games' builds except the linker maps listed in docs/CLEAN_ROOM.md
- [ ] If an AI tool wrote code or comments, I say which one here and I have read and checked what it wrote
