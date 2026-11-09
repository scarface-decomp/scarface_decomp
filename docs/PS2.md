# The PS2 version

The PlayStation 2 game (`SLUS_211.11`, US disc) is in the portal as a fourth version, next to the Xbox
game, the PC game and the April 2006 prototype. It is the same game built from the same C++, but for
another processor (the Emotion Engine, MIPS R5900) with another compiler, so it has its own lane, its own
progress row and its own way of being checked.

## How a PS2 function is checked

The compiler can't be shared or installed here, but decomp.me runs it:

| | |
| :--- | :--- |
| Compiler | Metrowerks CodeWarrior for PS2, 3.0.1 build 103 (`mwcps2-3.0.1b103-040528` on decomp.me) |
| Flags | `-O3 -lang c++ -str readonly` |
| Where it runs | decomp.me, through its compile endpoint (nothing is saved there by checking) |
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

* **Tail calls.** The game sometimes ends a function with a jump straight into the next one (`j func`),
  for example after setting a few fields. None of decomp.me's CodeWarrior builds did that with any flag
  we tried, so those functions (a few percent) can't match yet. If you find the setting or the source
  shape that makes the compiler do it, tell everyone.
* **Thunks.** Short `j` stubs at the start of some functions are made by the compiler for classes with more
  than one base class; they come from the class definitions, not from a function of their own.
* **Overlays.** The game loads extra code from `Overlays/` on the disc at run time. Only `SLUS_211.11`
  itself is in the queue.
* **One instruction form.** `sqrt.s` reads its operand from a field GNU as doesn't write, so in listings
  for decomp.me it is written as `.word`. The bytes are the same.

## Files

| | |
| :--- | :--- |
| `portal/tools/ps2_mips.py` | MIPS R5900 decoder and disassembler (GNU syntax) |
| `portal/tools/ps2_binary.py` | reading the program, finding functions, address fields, listings for decomp.me |
| `portal/tools/ps2_pairing.py` | pairing PS2 functions with Xbox ones (text and virtual tables) |
| `portal/tools/ps2_verify.py` | reading decomp.me's objects, the byte and address checks, decomp.me calls |
| `portal/verify.py --bin ps2` | the same check from the command line (`--scratch SLUG` to compile through a given scratch) |
| `reconstructed_src/Original_Binary_Order_PS2.cpp` | every PS2 function in address order, matched ones as their C++ |
