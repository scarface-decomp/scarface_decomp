# The PS2 version

The PlayStation 2 game (`SLUS_211.11`, US disc) is in the portal as a fourth version, next to the Xbox
game, the PC game and the April 2006 prototype. It is the same game built from the same C++, but for
another processor (the Emotion Engine, MIPS R5900) with another compiler, so it has its own lane, its own
progress row and its own way of being checked.

## How a PS2 function is checked

The project doesn't ship the compiler. decomp.me runs it:

| | |
| :--- | :--- |
| Compiler | Metrowerks CodeWarrior for PS2, 3.0.1 build 103 (`mwcps2-3.0.1b103-040528` on decomp.me); when that build's code is not the game's, 3.0 build 52 (`mwcps2-3.0b52-030722`) is tried. Each match records which build made it. "Two builds" below says why. |
| Flags | `-O3 -lang c++ -str readonly -Cpp_exceptions off` (until 25 November 2026 without the last two words; see "What the first run showed") |
| Where it runs | decomp.me, through its compile endpoint (nothing is saved there by checking); on your computer if you hold a licence for the compiler (below) |
| Where it is checked | the portal on your computer, against your own `binaries/SLUS_211.11` |

The portal sends your C++ to decomp.me, gets back the object file the PS2 compiler made, and compares
it with the game here, with the same rules as the PC and Xbox ([METHODOLOGY.md](METHODOLOGY.md)):

* **Same bytes.** Same length, same instructions, byte for byte.
* **Same connections.** Calls (`jal`), the two halves of an address (`%hi`/`%lo`) and small globals reached
  through `$gp` are compared apart from the address itself, and then the address is checked: a symbol
  named for an address (`func_0038F400`, `D_008088B8`) has to be that address, and a string or table your
  code defines has to be the bytes the game reads at that place.
* **No shortcuts.** No inline assembly, and no game addresses written as plain numbers.

So name what a function uses after its address: `extern "C" void func_00410470();`,
`extern int D_008088B8;`. That is the PS2 decomp convention, and it is how the verifier checks each
one. The portal's starting point for every PS2 function already declares them that way.

The decomp.me button opens the function as a scratch there (target written as assembly), with the same
compiler and flags. Its score is a helper: the portal's Compile & Verify is the check that counts.

### If you hold a CodeWarrior licence

`mwccps2.exe` is a commercial program, and it checks for a CodeWarrior licence when it starts. If you hold
one, put your copy of the same build (3.0.1 build 103) in `portal/tools/mwcps2/`, or name its folder in
`SCARFACE_MWCPS2`. The portal and `portal/verify.py --bin ps2` then compile on your computer, with
decomp.me's own command line and the same flags, and check the object by the same rules. The folder is not
part of the repository, and the project neither ships the compiler nor fetches it.

Without a licence the compiler refuses to run ("License check failed"). The portal treats that as the
compiler not being there and goes through decomp.me, as described next. Almost everyone is in that case.

### decomp.me goes through your browser

decomp.me turns away programs that aren't a browser (the portal gets `403 Forbidden`), and its pages cut
the link to windows opened from other sites. So the portal asks a decomp.me tab of yours to do the calls.
The first time a PS2 compile or a scratch needs it, the portal shows three steps:

1. Drag the **Scarface → decomp.me** button to your bookmarks bar (once; again if the portal's address
   changes).
2. Open decomp.me and, if it asks, tick its "verify you are human" box yourself.
3. Click the bookmark in that tab. If the browser asks whether decomp.me may reach apps on this device
   (or your local network), allow it: that is how it reaches the portal on `127.0.0.1`.

The tab then asks the portal for jobs, makes the scratch and compiles there, and sends the object back;
the portal checks it against your `SLUS_211.11` as above. The portal answers only decomp.me's own pages
(by their `Origin`), and only with the C++ and assembly of the function you are working on. Leave the
tab open while you work; the dialog closes by itself once it is connected.

## The PS2 easy pass

    python portal/scripts/ps2_easy_pass.py

has the portal try its own starter code on the open PS2 functions and record every exact match under
your handle, with no AI and no typing. Connect your decomp.me tab first (the three steps above) and leave
it open. Smallest functions first, it tries:

* **C++ written from two to four instructions** (`portal/tools/ps2_shapes.py`): an empty function, one
  that returns or stores a member of its object, one that returns a constant, its object, or a global,
  one that sets a member to a constant, adds to it, or reads through a pointer member. About 3,450 of
  the PS2 game's functions have one of these shapes. On its first night the pass matched 976 of the
  978 functions it tried.
* **A matched look-alike's C++**, with this function's addresses.
* **The matched Xbox function's C++**, for a PS2 function paired with one, when that code names no
  address (Xbox addresses would be wrong here).

Each is compiled and checked like any submission; nothing counts unless the game's compiler gives back
the same bytes with every address checked.

decomp.me is a free service shared by many projects, so the pass is a light user of it on purpose:

* every compile goes through one scratch (compiling saves nothing there), so no scratches pile up;
* the same text is never compiled twice: the object is kept and reused, so the 600 empty functions cost
  one compile;
* real compiles are two seconds apart, and a run stops after 400 of them. Run it again later to go on
  from where it stopped (`SCARFACE_PS2_EASY_PAUSE` and `SCARFACE_PS2_EASY_MAX` change the two numbers;
  please don't make it heavier).

When your decomp.me tab is connected, the portal's own Compile & Verify uses it by itself too.

After the portal restarts, or while the decomp.me tab is in the background, the browser can take up to a
minute to let the tab ask the portal again. The pass waits for it (75 seconds) before it gives up, and
goes on by itself when the tab comes back. Keeping the tab in a window of its own, in view, avoids the wait.

## Probing other optimisation flags

    python portal/scripts/ps2_flag_probe.py

Every try that gave the game's bytes is listed again at the end, and everything the run printed is saved
in `work/ps2_probe.txt` (never committed), so nothing is lost when the screen scrolls.

The lane's first flags (`-O3 -lang c++ -str readonly`) matched the smallest functions everywhere, but two
things they did not reproduce (first easy-pass runs, November 2026):

* a call as a function's last statement that the game turns into a jump (`0x003EB610`: the compiler makes
  an ordinary call with a stack frame, 32 bytes against the game's 12, with or without `#pragma tailcall on`);
* a float stored and then 1 returned, where the game stores first (`0x00392940`: the compiler puts the
  store in the delay slot; the same source with an integer store matches).

The examiner's census of the program shows both are how the whole game was built, not one part of it:
1,772 functions end in such a jump, in every part of the game's code and next to functions the lane's
flags already match, and every float-store-then-return-1 function has the store first. So the answer is
one compiler build or one setting for the whole game.

The probe compiles one function's C++ through your decomp.me tab with other builds or flags and prints how
close each gets, with the compiled instruction words. It records nothing. Give it a file and `--va`, with `--compiler`
and `--flags`, for your own. Only decomp.me's PS2 builds and optimisation words are accepted, one compile
per line, two seconds apart.

### What the first run showed (25 November 2026)

All 23 builds with the lane's flags, then build 103 with `-O2` to `-O4`, speed, space and `-inline auto`:

| Question | Result |
| :--- | :--- |
| The call that should be a jump (`0x003EB610`) | No build and no setting made the jump. Every one wrote an ordinary call with a 16-byte frame (32 bytes; 40 at `-O2`). |
| The float store that should come first (`0x00392940`) | Eight builds match: 2.3, 3.0, 3.0.1 (January 2002), 3.0.3, and 3.0 builds 22, 38, 50 and 52. Every 3.0.1 build from 44 on, the lane's among them, puts the store in the delay slot at `-O3` and `-O4`, and at `-O2` leaves the delay slot empty. |

So the builds that keep the store first are the ones the table below rules out (they never write `madda.s`
chains), and the builds that write those chains move the store. No build decomp.me has does both with these
flags, which leaves a setting that hasn't been tried, or a build decomp.me doesn't have.

The compiler's own help text said what to try. It lists what optimisation level 3 adds: "instruction
scheduling, tail call optimization". The jump is that tail call optimisation, so something was turning it
off, and C++ exceptions were the first suspect: a function that may have to be unwound keeps its frame, and
the lane's flags left them on.

**The second run settled the first question.** Build 103 with `-O3 -lang c++ -str readonly -Cpp_exceptions
off` gives `0x003EB610` exactly: two arguments, a jump, 12 bytes (`-RTTI off` and `-O4,p` on top change
nothing there). The game was built with C++ exceptions off, and since 25 November 2026 so is the lane.

* Matches recorded before that keep the flags they were compiled with. All 3,112 of them are functions that
  call nothing, where exceptions make no difference to the code; none has been compiled again to show it.
* The easy pass tries every open function again with the new flags, the two families that end in a jump
  among them.

**The second question is open.** With exceptions off the float store still goes into the delay slot, and
the third run showed it does so with every setting tried: `-O3` and `-O4` with speed, space and inlining,
RTTI off, and the scheduler or the peephole pass turned off (`-opt noschedule`, `-opt nopeephole`), which
gave the same bytes as leaving them on. The jump, meanwhile, matched with every `-O3` and `-O4` setting once
exceptions were off, and with none at `-O2`.

### What the fourth run showed (25 November 2026)

32 compiles: the 3.0 line of builds, a dot product, and other ways of writing the two test functions.

| Question | Result |
| :--- | :--- |
| The jump and the float store on 3.0.3 and 3.0 builds 38, 50, 52, lane flags | All eight match. |
| A dot product the game writes as load, load, `mula.s`; load, load, `madda.s`; load, load, `madd.s` in the delay slot (`0x0066DFF0`, 40 bytes) | **No build matches.** Builds 87 and 103 write the right three multiply instructions but load all six floats first, into six registers (16 of 40 bytes). The 3.0-line builds also load first and write `mul.s`, `mul.s`, `adda.s`, `madd.s` (44 bytes), with or without `#pragma usefloatacc on` and `#pragma fastmath on`. |
| The float store on build 103 with a `#pragma` | `#pragma schedule off` puts the store first but leaves the delay slot empty (`swc1; li; jr; nop`, 16 bytes), as `-O2` does. `peephole off`, `usefloatacc off`, `fastmath on`, `memoryrewrite off` and `conditional_move off` change nothing. |
| The float store on build 103 written another way (returning `int`, as one expression, as a plain function) | No change. |
| A jump after reading a global from its full address (`0x0038EC30`: `lui $at; j; lw $a0`) | The easy pass's text compiles to `lui $v0; j; lw $a0` (4 of 12 bytes): another register for the address. With the global declared as a pointer it is read through `$gp` (8 bytes). |
| A jump passing the object, one of its members and a zero (`0x0037DBF0`) | Matches on build 103: `func(this, m_FieldD0, 0)` as the last statement. |

What that adds up to:

* The 3.0 line is out again, on the dot product: it does not write `madda.s` chains with these settings. The
  table below stands on that point.
* The lane's build is not the whole answer either. It differs from the game in three places: the float
  store comes after the return value, the six loads of the dot product come before the multiplies, and an
  address used once goes through `$v0` where the game uses `$at`. In the first two the game has the order
  the source has. With its scheduler off, build 103 keeps that order for the float store, but leaves the
  delay slot empty, and the game fills it. Whether the other two follow the scheduler is not tested yet.
* `-opt noschedule` on the command line changed nothing where `#pragma schedule off` did, so the flag is
  not the pragma.

### What the fifth run showed (25 November 2026)

33 compiles: `#pragma schedule off` on every 3.0.1 build, and the global-then-jump shape on the 3.0 line.

| Question | Result |
| :--- | :--- |
| The float store with the scheduler off, 3.0.1 builds 44 to 210 | All twelve: store first, delay slot empty (16 bytes). No 3.0.1 build fills the slot with its scheduler off. |
| The dot product with the scheduler off, builds 44 to 75 | Each pair of loads next to its multiply, as the game has them, but `mul.s`, `mul.s`, `adda.s`, `madd.s` and the second term first (48 bytes; 28 of 40). |
| The dot product with the scheduler off, builds 87 to 210 | The right three multiplies, but all six loads still first, and the delay slot empty (44 bytes; 9 of 40). |
| A jump after reading a global (`0x0038EC30`) on 3.0.3 and 3.0 builds 38, 50, 52 | **All four match**: they use `$at` for the address, as the game does. |
| That jump on builds 87, 95, 103 with the scheduler off, or with the global as a member of a larger object | `$v0` for the address every time. |

### Where the compiler question stands

No build decomp.me has makes all of what the game has:

| What the game's code has | 3.0 line (3.0.3, 3.0 builds 38 to 52) | 3.0.1 builds 44 to 75 | 3.0.1 builds 87 to 210 |
| :--- | :--- | :--- | :--- |
| A last call turned into a jump (exceptions off) | yes | not tried | yes |
| A float store kept before the return value, with the delay slot filled | yes | no | no |
| `$at` for an address used once | yes | not tried | no |
| A sum of three products as `mula.s`, `madda.s`, `madd.s` | no | no | yes |
| Each pair of float loads next to its multiply | no | only with the scheduler off | no |

The first three rows are how the 3.0 line orders instructions and picks registers; the fourth is float code
that first appears in the 3.0.1 line between build 75 (September 2003) and build 87 (December 2003). The
game was built in 2006. The likeliest reading is a build decomp.me does not have: one that orders and
allocates like the 3.0 line and has the later float code. That is a reading of five test functions, not a
census, and the examiner's round (Q55 to Q67) is checking it against the whole program.

What this means for the lane today: build 103 with exceptions off gives the game's bytes for the small
functions matched so far, and will not for float-heavy code or for the shapes in the first three rows.

### Two builds

Since 25 November 2026 the portal compiles a PS2 submission with build 103 and, when that does not give
the game's bytes, with 3.0 build 52. Neither is the game's compiler, and the table above says what each
gets right: build 103 the float code, build 52 the order of instructions and the choice of registers. A
match made by build 52 says so in the registry (`compiler`) and in its block in `reconstructed_src/`
(`Build:`).

What that claim is and is not:

* It is: this C++, compiled by a named, real build of the game's compiler family, gives the game's exact
  bytes with every address checked.
* It is not: proof that the game was built with that build. If the game's own build turns up, every match
  is compiled again with it (`--recheck` below does that for a sample today).
* `--recheck` found both builds give the game's bytes for 30 of 30 already-matched functions (one for each
  way of writing one), so the small functions do not tell the two apart. That run also showed the matches
  recorded before exceptions were turned off still hold.
* Code that needs both at once (float sums in source order with `$at`, say) matches on neither build.

### Checking another build against what is matched

    python portal/scripts/ps2_flag_probe.py --recheck

compiles 30 functions that are already matched (one for each way of writing one: half the commonest ways,
half the largest functions) with the last 3.0-line build (3.0 build 52) and with the lane's own, and says
how many each gives back. It answers two things: whether build 52 also makes the small functions, which
would make it the better build for everything but float code; and whether the matches recorded before
exceptions were turned off still come out the same. `--compiler` names other builds; a number after
`--recheck` changes the 30.

### The easy pass's first run with exceptions off

377 functions matched in 400 compiles, all of them the 12- and 16-byte shapes left over from the earlier
runs. No jump matched, and that was the trial rule, not the flags. The pass took "ends in a jump" for one
family and gave it six tries; in address order those went to two functions it has no code for and four of
one shape (a global read from its full address, then the jump: `lui $at; j; lw $a0`), all of which failed.
The shape the probe had proved, two small-data addresses and a jump (45 functions), was never reached.

Each way of writing a jump is now a family of its own (ten of them, 145 functions), with its own six tries,
and a function the pass has no code for is on no trial. Another 114 three-instruction jumps pass constants,
zeros and arguments the pass does not write yet.

## How the compiler was worked out

The program says `MW MIPS C Compiler (2.4.1.01)` in its `.comment` section, but five different builds write
that same text, so it doesn't settle it. decomp.me has 23 CodeWarrior builds for the PS2; the game's own
code ruled out all but one family:

| Evidence in the game's code (3.3 MB, 0x37A780 to 0x700000) | What it rules out |
| :--- | :--- |
| Not one "branch likely" instruction, while builds 145 and later write them all the time at `-O3` | 3.0.1 build 145 and later |
| About 1,700 `madda.s` multiply-accumulate chains, and 396 counted loops that skip the jump into the loop | the 2001-2002 builds (2.x, 3.0, 3.0.3, 3.0b), which never write either |
| Float loads done one after another (74 places) rather than all first (5) | build 95, which loads them first |
| Half of the branch delay slots filled | build 119, which leaves 85% of them empty |

Builds 87 and 103 (December 2003 and May 2004) are left, and they made the same code in every test but a
64-bit multiply. Real game functions then matched exactly: `0x003DD090` (a loop resetting 30 items) is
[scratch zl1xw](https://decomp.me/scratch/zl1xw) on decomp.me, and `0x00415400` (emptying a linked list)
matched too. `-str readonly` is what puts string literals where the game has them (reached with
`lui`/`addiu`, not through `$gp`).

## What the portal does with the program

* **Gets it off your disc.** Put the PS2 disc image (`.iso`, or the `.7z`/`.zip` it came in, with "ps2" in
  its name) or `SLUS_211.11` itself in `binaries/`. The portal reads `SLUS_211.11` out of the image's root
  without unpacking it. Only the US disc's program is accepted ([GAME_VERSIONS.md](GAME_VERSIONS.md)).
* **Finds the functions.** The program has no names, so functions are found from the code: every call and
  jump target, every function address in the data (virtual tables, callbacks), and whatever starts right
  after another function ends. Sizes come from following each function's branches. Switch jump tables are
  read so their cases aren't taken for functions. The code reassembles from these listings to the
  identical 4.2 MB, which is how the finder and the disassembler were tested.
* **Leaves out the Sony libraries.** They were built with GCC, which uses "branch likely" everywhere and
  aligns functions to 8 bytes; the game's own code never does either. About 600 library functions are
  left out; 23,567 game functions are in the queue.
* **Names what it can from the Xbox game.** A PS2 function that uses exactly the same text as one Xbox
  function (and no other function on either side does) is that function. Once two functions in a PS2
  virtual table are paired that way with the same places in an Xbox class's table, the whole table lines
  up and gets the class's method names. That pairs about 1,300 PS2 functions with their Xbox twin and
  names about 640 (`FrontEndFlowClient::vfunc_03`, ...). When the Xbox twin is matched, its C++ becomes the
  PS2 function's starting point. These are hints: the PS2 function is still verified on its own.
* **Groups look-alikes.** PS2 functions with the same code apart from addresses are grouped like the
  others, and a match is carried to the rest of its group.

## Known gaps

* **Tail calls.** The game sometimes ends a function with a jump straight into another one (`j func`, or
  `jr $t9` for a virtual method), for example after setting up two arguments. The examiner's reading of
  the compiler's own option text is that this is its tail-call optimisation, on from `-O3`, and that it
  only happens when the function needs no stack frame of its own; so the source is an ordinary call as the
  last statement of a function that returns nothing, such as `void f() { g(&a, &b); }`. That source gives
  the jump once C++ exceptions are off (the probe, above), which the lane's flags now are. The easy pass
  writes it for the three-instruction cases and for virtual forwards, as shapes on trial: if one of those
  families does not match once in its first six tries of a run, the pass leaves it alone and says so.
* **A float stored before a value is returned.** The game stores first; the lane's build puts the store in
  the delay slot (the probe's second question, above).
* **Thunks.** Short `j` stubs at the start of some functions are made by the compiler for classes with more
  than one base class; they come from the class definitions, not from a function of their own.
* **Overlays.** The game loads extra code from `CEMENT.RCF/Overlays/FrontEnd/` when it needs it: six
  CodeWarrior overlays with 730 functions between them (below).
* **One instruction form.** `sqrt.s` reads its operand from a field GNU as doesn't write, so in listings
  for decomp.me it is written as `.word`. The bytes are the same.

## The overlays

Some of the front end isn't in `SLUS_211.11` at all: the game keeps it in six code overlays on the disc
(`CEMENT.RCF/Overlays/FrontEnd/`) and loads one at `0x845480` when it needs it. The portal copies the six
`...f.bin` files (the build that fits the retail program; layout in
[FORMATS.md](FORMATS.md#ps2-code-overlays)) out of your PS2 disc into `binaries/ps2_overlays/` when it
starts, together with the scripts, and their functions go in the work queue under **PS2 menus**:

| Lane | File | Functions | What is in it |
| :--- | :--- | ---: | :--- |
| PS2 overlay: pause menu | `PauseMenuOverlayf.bin` | 191 | `PauseMenu` and its pages (options, controller, stats, rewards, credits) |
| PS2 overlay: exotics shop | `ExoticsOverlayf.bin` | 115 | `ExoticsHUD2`, `MissionCompleteHUD`, `RepGainHUD` |
| PS2 overlay: business screens | `ModalsOverlayf.bin` | 124 | `DrugWarsHUD`, `BusinessHUD`, `VehicleSelectionHUD`, `ViceCopHUD` |
| PS2 overlay: empire and mansion screens | `ModalsOverlay1f.bin` | 102 | `EmpireHUD`, `PimpYourMansionHUD`, `LookTutorialHUD` |
| PS2 overlay: weapon screens | `ModalsOverlay2f.bin` | 70 | `GenericWeaponHUD` and its locker, street and phone panels |
| PS2 overlay: gambling mini-games | `MiniGamesOverlayf.bin` | 128 | `FightBettingHUD`, `BlackjackHUD`, `PokerHUD`, `SlotMachineHUD` |

They are checked like the rest of the PS2 game, against the program with that overlay loaded: calls into
the program are `func_XXXXXXXX` and its globals `D_XXXXXXXX` as usual, and the overlay's own functions
and data have addresses from `0x845480` on. All six use the same addresses, so a function's key says
which overlay it is in (`ps2pause:0x00845830`). As with the program, functions are paired with the Xbox
game's where the text they use or their place in a virtual table gives it away (the program was linked
together with its overlays, so their virtual tables are in `SLUS_211.11`'s data): about 130 of them, about
70 with a name.

To look at one in Ghidra, IDA or objdump, `portal/tools/ps2_overlay.py --elf FOLDER binaries/ps2_overlays/*.bin`
writes each as an ELF file that opens at its load address; open it next to `SLUS_211.11`.

## Files

| | |
| :--- | :--- |
| `portal/tools/ps2_mips.py` | MIPS R5900 decoder and disassembler (GNU syntax) |
| `portal/tools/ps2_binary.py` | reading the program, finding functions, address fields, listings for decomp.me |
| `portal/tools/ps2_overlay.py` | the front-end overlays: their headers, which build fits, ELF files for Ghidra and IDA |
| `portal/tools/ps2_shapes.py` | C++ for the smallest functions, written from their instructions |
| `portal/scripts/ps2_easy_pass.py` | runs the PS2 easy pass on your portal |
| `portal/scripts/ps2_flag_probe.py` | tries other optimisation flags on one function |
| `portal/tools/ps2_pairing.py` | pairing PS2 functions with Xbox ones (text and virtual tables) |
| `portal/tools/ps2_verify.py` | reading the compiler's objects, the byte and address checks, compiling here or on decomp.me |
| `portal/verify.py --bin ps2` | the same check from the command line (`--scratch SLUG` to compile through a given scratch) |
| `reconstructed_src/Original_Binary_Order_PS2.cpp` | every PS2 function in address order, matched ones as their C++ |
