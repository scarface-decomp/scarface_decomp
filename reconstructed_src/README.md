# reconstructed_src

Verified C++ for the game goes here. It is empty because the count was **reset on 2026-11-08**:
every function is rebuilt and verified again from scratch, so nothing here depends on work done
before the project's tools and rules were finished.

You don't add files here by hand. When a function verifies in the portal, the portal writes it into:

* `Original_Binary_Order_PC_1002.cpp` / `Original_Binary_Order_Xbox.cpp`: every verified function in
  address order;
* `pc/<subsystem>/<Class>.cpp` and `xbox/<subsystem>/<Class>.cpp`: the same functions grouped by class;
* `Partial_Proven_Checkpoints.cpp`: best partial attempts (not verified).

All of these are generated from `reports/verified_registry.json`. The work from before the reset is
kept in git history (tag `pre-reset-2026-11-08`), for reference only: it counts again only after it
verifies through the portal.
