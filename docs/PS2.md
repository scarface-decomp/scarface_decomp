# The PS2 version

The PlayStation 2 game (`SLUS_211.11`, US disc) is in the portal as a fourth version, next to the Xbox
game, the PC game and the April 2006 prototype. It is the same game built from the same C++, but for
another processor (the Emotion Engine, MIPS R5900) with another compiler, so it has its own lane, its own
progress row and its own way of being checked.

## How a PS2 function is checked

The project doesn't ship the compiler. decomp.me runs it:

| | |
| :--- | :--- |
| Compiler | Metrowerks CodeWarrior for PS2, 3.0.1 build 103 (`mwcps2-3.0.1b103-040528` on decomp.me) |
| Flags | `-O3 -lang c++ -str readonly` |
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

The lane's flags (`-O3 -lang c++ -str readonly`) match the smallest functions everywhere, but parts of the
game may have been built with other optimisation settings, as the Xbox game's libraries were. Two things
the lane's flags do not reproduce (first easy-pass runs, November 2026):

* a call as a function's last statement that the game turns into a jump (`0x003EB610`: the compiler makes
  an ordinary call with a stack frame, 32 bytes against the game's 12, with or without `#pragma tailcall on`);
* a float stored and then 1 returned, where the game stores first (`0x00392940`: the compiler puts the
  store in the delay slot; the same source with an integer store matches).

The examiner's census of the program shows both are how the whole game was built, not one part of it:
1,772 functions end in such a jump, in every part of the game's code and next to functions the lane's
flags already match, and every float-store-then-return-1 function has the store first. So the answer is
one compiler build or one setting for the whole game.

The probe compiles one function's C++ through your decomp.me tab with other builds or flags and prints how
close each gets, with the compiled instruction words. It records nothing. Run without arguments it asks
those two questions with all 23 CodeWarrior for PS2 builds decomp.me has (lane flags), then with the lane's
build and 11 other settings (`-O2` to `-O4`, speed and space). Give it a file and `--va`, with `--compiler`
and `--flags`, for your own. Only decomp.me's PS2 builds and optimisation words are accepted, one compile
per line, two seconds apart.

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
  last statement of a function that returns nothing, such as `void f() { g(&a, &b); }`. The easy pass now
  writes that for the three-instruction cases and for virtual forwards, as shapes on trial: if one of
  those families does not match once in its first six tries of a run, the pass leaves it alone and says so.
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
