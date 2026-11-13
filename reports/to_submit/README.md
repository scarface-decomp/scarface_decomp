# Matches waiting for the portal

Each `.cpp` here matched its function byte for byte with `portal/verify.py`, but isn't recorded yet: only the
portal can do that. With the portal running, send them under your own name:

    python portal/scripts/submit_matches.py

It asks for your handle and PIN, has the portal verify each file, and deletes the ones it recorded. Then
commit `reports/` and `reconstructed_src/` as the portal left them.

The comment lines at the top of each file say which function it is (`bin`, `va`), what it does (`what`,
saved as the match's description) and where the knowledge came from (`spec`).
