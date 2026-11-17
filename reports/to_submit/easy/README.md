# Easy-pass matches waiting to be recorded

2,151 functions (991 Xbox, 863 prototype, 297 PC) that the portal's own starter code matches byte for
byte, with no AI. They were found on 17 November 2026 by running the starter code over every open
function of 96 bytes or less and checking each with the project's verifier and the real compiler
(`msvc_verify.verify_submission`: exact bytes, every reference checked, no hard-coded addresses).

They are not in the registry yet: only the portal records a match. With the portal running, anyone
can record them under their own name:

    python portal/scripts/submit_matches.py --folder reports/to_submit/easy

The portal compiles and checks every file again, records the ones that match and deletes those files.
Then commit `reports/` and `reconstructed_src/` as the portal left them. Pressing **Match the easy
ones** in the portal finds the same functions without these files; this folder only saves the wait.

The names in these files are stand-ins (`m_Field08`, `sub_00123456`), as in all starter code.
