# reconstructed_src

Verified C++ for the game goes here. It is empty because the count was **reset on 2026-11-08**:
every function is rebuilt and verified again from scratch, so nothing here depends on work done
before the project's tools and rules were finished.

You don't add files here by hand. When a function verifies in the portal, the portal writes it into:

* `Original_Binary_Order_Xbox.cpp`, `Original_Binary_Order_PC_1002.cpp`, `Original_Binary_Order_Proto.cpp`:
  **every** function of that game file in address order, the order it has in the game. Matched functions are
  their C++; the ones not matched yet are one `// [TODO] address name (size)` line each, in their place, so
  you can see what is missing and where. The header of each file says how complete it is;
* `pc/<subsystem>/<Class>.cpp` and `xbox/<subsystem>/<Class>.cpp`: the same functions grouped by class;
* `Partial_Proven_Checkpoints.cpp`: best partial attempts (not verified).

All of these are generated from `reports/verified_registry.json`. `include/` holds the shared headers,
and `CMakeLists.txt` lets an IDE index the hand-written files. The work from before the reset is
kept in git history (tag `pre-reset-2026-11-08`), for reference only: it counts again only after it
verifies through the portal.
