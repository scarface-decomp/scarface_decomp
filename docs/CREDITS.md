# Credits

## Project

* **RRutherrfordd (Founder) / RogiPogee**: project lead, original analysis and the portal.

## Contributors

Everyone who verifies a function through the portal is recorded by handle in
`reports/verified_registry.json` (`verified_by`) and shown on the portal's leaderboard. Pull request
authors are credited in the commit history. Thank you.

## Tools and references

* [Capstone](https://www.capstone-engine.org/) disassembler, used for function sizing and checks.
* The Microsoft Visual C++ Toolkit 2003 (cl.exe 13.10.3052 or 13.10.3077), which each contributor supplies.
* Prior matching-decompilation projects whose methods informed this one, among them
  [fnv_decomp](https://github.com/momusdigital/fnv_decomp) (Fallout: New Vegas, MSVC),
  the [Halo 2 decompilation](https://github.com/kirklandsig/halo2-decompiled) (Xbox, MSVC 7.1) and
  [LEGO Island](https://github.com/isledecomp/isle) with its [reccmp](https://github.com/isledecomp/reccmp)
  tools (MSVC 4.2). No code was taken from them.
* [decomp.me](https://decomp.me), which hosts the same compiler (`msvc7.1`) for working on functions in
  the browser.
* For the script and archive formats: the [STWIY ToolKit](https://github.com/STWIY/ToolKit) (layout of
  `.rcf` archives), [Broken Face](https://github.com/sulzbals/BrokenFace) by sulzbals and Meth0d's
  write-up on Scarface's compiled TorqueScript (layout of `.cso` / `.dso`). Their documentation was
  read; no code was copied.
* For compiling TorqueScript the way the game does: the code generator of
  [Torque2D](https://github.com/TorqueGameEngines/Torque2D) (`astNodes.cc`, `compiler.cc`, MIT
  licence), the open-source descendant of the engine Scarface's script compiler came from. It was read
  to get the order of the string, number and name tables right; the Python compiler here is new code.
