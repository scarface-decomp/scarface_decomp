# Instructions for AI agents

Read [SCARFACE_DECOMP_AI_HANDOFF.md](SCARFACE_DECOMP_AI_HANDOFF.md) first: it explains what a matching
function is, what the verifier accepts and the code generation facts for this compiler. The rules in
[docs/METHODOLOGY.md](METHODOLOGY.md) are the ones the verifier enforces.

## Working through the local portal

The portal (`python portal/decomp_portal_server.py`, default `http://127.0.0.1:8085`) is the only thing that
can record a function as verified. Every request that changes something needs the contributor's
`user` (handle) and `pin`; ask the person you are working for, and never store or print the PIN.

| Step | Request | Notes |
| :--- | :--- | :--- |
| Find work | `GET /api/queue?tier=TIER_1_QUICK&page=1&limit=80` | also `q=` (symbol or address), `sort=SIZE_ASC` |
| Read a task | `GET /api/task?id=<id>` | `target_hex`, `disasm_lines`, `size`, `symbol`, `starter_cpp` |
| Claim it | `POST /api/claim {"user", "pin", "id"}` | a timed lease; fails if someone else holds it |
| Check code | `POST /api/verify {"user", "pin", "id", "cpp_code", "tool_used"}` | returns `matched_bytes`, `total_bytes`, `diff_details`, `verified` |
| Give up | `POST /api/cancel {"user", "pin", "id", "cpp_code"}` | releases the claim and keeps your best partial attempt |
| decomp.me target | `GET /api/decompme?id=<id>` | `obj_b64` (COFF target), `fields` for `POST https://decomp.me/api/scratch`, `existing_url` |
| Remember a scratch | `POST /api/decompme {"id", "slug"}` | or `{"id", "create": true}` to have the portal create it |

Without the portal, `python portal/verify.py file.cpp --va 0x... --bin pc|xb --show-diff` applies the same
rules but records nothing.

## Rules

* Only the compiler's verdict counts. Never report a function as matched unless `verified` is `true`.
* Claim before you work on a function, and cancel when you stop, so nobody duplicates the effort.
* Plain C++ only: no inline assembly, `_emit`, `naked` functions, section pragmas or byte arrays.
* No 2006 addresses as numbers: use address-named externs such as `extern "C" char DAT_00439DA4;`.
* Don't edit `reports/verified_registry.json` or the generated files (`Original_Binary_Order_*.cpp`,
  `reconstructed_src/pc/`, `reconstructed_src/xbox/`) by hand.
