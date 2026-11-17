# Roadmap: from matched functions to a source tree

Where the project is, where finished decompilations of games from this era end up, and the steps
between. Numbers are from 14 November 2026.

## Today

- 10,373 functions compile byte for byte: 6,901 of 21,050 in the released game (Xbox and PC), 3,472 in
  the 2006 Xbox prototype.
- Each function is its own small file with its own copy of the class it belongs to, holding only the
  members that function uses. Two functions of one class can declare it differently.
- Calls and globals are written by address (`sub_0011E4A0`, `DAT_00439DA4`). That name is the proof:
  the verifier reads the address out of it. A name from `reports/names.json` works the same way.
- Nothing is compiled together, linked or run.
- The byte check runs on a contributor's computer. GitHub's checks cannot run it: the 2003 compiler
  can't be installed there.

## Where this should end up

A source tree: one file per original source file, shared headers with one declaration per class, real
names throughout, one table that says which function lives at which address, and one command that
builds everything and compares it with the game. Every change checked by rebuilding what it touches.

## Steps, in order

Each step is useful by itself and none throws away what exists.

### 1. Match what the tools can already match
Run **Match the easy ones** over the whole queue, then Batch Run. Nothing to build. A sample suggests
several thousand functions match from the portal's starter code alone.

### 2. Names on record (started)
- `reports/names.json` ties a name to an address, with a reason. 406 names so far.
- Code may call a function by its recorded name, and may define a function under its recorded name; the
  address is checked either way.
- Still to do: names for globals and for class members, the same way (a name, an address or offset, a
  reason), so `DAT_00439DA4` and `m_Field64` can go too. Step 3's merged classes are where a member's
  name will live.

### 3. One declaration per class (started)
The step that turns snippets into source.
- `python portal/scripts/merge_classes.py` merges what each class's matched functions declare
  (members by offset, virtual functions by slot, other member functions) into one class.
  With `--verify` it recompiles every function of the class with the merged class in place of its own
  copy, and keeps the class only for the functions that still compile to the game's bytes.
- Measured on 17 November 2026 (15,630 matched functions, 8,322 of them member functions of 2,477
  classes and templates): **1,335 classes have a proven merged declaration, covering 5,919
  functions.** They are in `reports/classes/`, and `reports/classes.json` says how every class went.
  So this is a tool, not hand work.
- Every instance of a template (`ConcreteClassRep<X>` for each X) is merged under the one template
  declaration its functions are written against.
- What is left out, and why (`reports/classes.json` names each function):
  - About 730 functions that no longer compile, or compile differently, with the merged class: two
    copies type one member differently (an `int` in one, a pointer in another), or two instances of a
    template define a slot with different signatures. A person or a smarter rule picks.
  - 458 functions whose class holds another object as a member (`Field20 m_Field20;`), and 67 with a
    base class: the tool does not read those yet.
  - 1,039 classes with only one matched function so far: nothing to merge.
- Still to do: make each function's recorded text use the merged class (through the portal, so the
  registry stays the proof), and carry a member's name from `reports/names.json` into every function of
  its class.

### 4. Files and one build command
- Group functions into files by address order and class (the original file boundaries are not known;
  address order is the evidence there is).
- `build/units.json`: each file, its compiler flags, and the functions expected in it with their
  addresses. The address-in-the-name trick is then no longer needed.
- One command that compiles every unit and compares every function with the game.

### 5. A check on every change
- On GitHub if a compiler that produces the same code can be run there; otherwise on a maintainer's
  machine before every merge, with the result recorded.
- A change that alters compiled output fails. Renames and comments pass.

### 6. Running code
- A harness that calls matched, self-contained functions and checks what they return.
- Linking matched objects in place of the originals, one at a time.

## What is not on this list

PS2 (another compiler, nothing matched yet) and the unreadable part of the PC program stay as they are
until the Xbox build is much further along.
