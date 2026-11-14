# Function names, for Ghidra and IDA

The project knows where every function in the game starts and how long it is, on all four versions, and a
good share of their names. Two scripts put all of that into your own Ghidra or IDA project, so you start
with the functions found and named instead of from scratch.

| Version | Functions | Named so far |
| :--- | ---: | ---: |
| Xbox `default.xbe` | 19,534 | 7,160 |
| Xbox prototype `game.xbe` (April 2006) | 17,904 | 6,764 |
| PS2 `SLUS_211.11` | 23,567 | 843 |
| PC `Scarface.exe` 1.00.2 (the part that isn't encrypted, see [GAME_VERSIONS.md](GAME_VERSIONS.md)) | 1,516 | 768 |

(As of November 2026. The counts grow with every match and every name added; the lists themselves are
the address-order files in [`reconstructed_src/`](../reconstructed_src).)

## Where the names come from

* **The game's own class information.** The Xbox, prototype and PC programs keep C++ run-time type
  information: the name of each class with virtual functions, and its table of them. That gives names
  like `CoverObject::vfunc_29`: the 30th virtual function of `CoverObject`. The class is certain; the
  number says which slot, until someone works out what the function does.
* **PS2 to Xbox pairing.** The PS2 program has no class information. Its functions are paired with
  the Xbox's by the strings only the two of them use and by matching places in their tables of virtual
  functions, and get the Xbox name ([PS2.md](PS2.md)).
* **Matches.** A verified function has the name it was matched with.
* **The game's script commands.** Every command a script can call (`GetGameTime()`,
  `%tony.AddHealth(...)`) is a function the program registers under that name when it starts, so the
  program itself says which function is which. `portal/tools/script_commands.py` reads the 820
  registrations out of `default.xbe` and names the function behind each one `Script::<Command>` (or
  `Script::<Class>_<Command>`): 397 functions on the Xbox so far that the queue only knew by address.
  That these commands exist was known from the modding scene first: ScarfaceHook and ScarfaceEX call
  them by name ([CREDITS.md](CREDITS.md)).
* **Published research.** A name another project worked out and published under a licence that allows
  it, with the project named in `by`, and checked against the code: so far the PC's
  `core::CementLibrary::OpenFileByHash`, from RCFRedirect.
* **People.** Names worked out by hand are in [`reports/names.json`](../reports/names.json), with the
  two kinds above.

Everything else keeps an address name: `sub_00011010` (Xbox, PC, prototype) or `func_00390320` (PS2).

## Ghidra

1. Load the program: `default.xbe` or `game.xbe` (with an XBE loader extension), `Scarface.exe`, or
   `SLUS_211.11` (with the Emotion Engine extension for the R5900's own instructions). Let Ghidra analyse it.
2. **Window > Script Manager**, then **Manage Script Directories** (the list icon) and add
   `portal/scripts` from your copy of this repository.
3. Run **ghidra_scarface_names.py** (category *Scarface*). Pick the repository folder; it guesses the
   version from the program's name and asks you to confirm.

It creates the functions Ghidra missed at their exact starts, names them (`Class::name` becomes the
function `name` in the namespace `Class`), and marks verified ones in their comment. Names Ghidra already
has from you are replaced only for functions the project has a name for. Headless:
`analyzeHeadless ... -postScript ghidra_scarface_names.py <repository folder> xb` (`xb`, `pc`, `ps2` or
`proto`).

## IDA

With the program loaded and analysed: **File > Script file...**, pick
`portal/scripts/ida_scarface_names.py`, then any file in your copy of the repository (`README.md` will
do), and confirm the version. IDA 7.4 or later. Where IDA won't take a character in a name (some allow
`::`, some don't), it puts `_` in its place.

Run either script again whenever you pull: it only adds and renames.

## Adding a name

Names follow [PROVENANCE.md](PROVENANCE.md#names): they come from the game's class information, the
strings a function uses, or what its code does, and never from leaked symbols or debug data. A careful
guess is fine; say it is one.

Worked out what a function does? In the portal, under the function's name, **Suggest a name** opens a
GitHub issue with the function filled in: give the name and a sentence on what shows it (the strings it
uses, what calls it, the PC or Xbox function it matches). A maintainer adds it to `reports/names.json`.

Or add it yourself with a pull request:

```json
"xb:0x0011E4A0": {"name": "Weapon::Reload", "by": "your handle", "why": "plays reload.rsd and refills the clip"}
```

Keys are a version (`xb`, `pc`, `ps2`, `proto`) and the address where the function starts, as in the
`reconstructed_src/` lists. CI checks the file (`python portal/tools/names.py`): a C++ name, who worked it
out, why, and a function that really starts there. A name is a label, not a match: the function still
needs its C++ verified like any other.

## Using a name in matched code

Matched code calls other functions by their address (`sub_0011E4A0`), because that is how the verifier
checks the call goes to the right place. Once a function has a name in `reports/names.json`, code may
call it by that name instead and the check still holds: the verifier reads the name back from the
compiled object and compares the address the file gives it.

```cpp
class Weapon { public: void Reload(); void sub_00011000(); int m_ammo; };
void Weapon::sub_00011000() { m_ammo = 0; Reload(); }      // Reload is checked against 0x0011E4A0
```

A name nobody has tied to an address is not checked, so the portal won't keep a cleaned-up version that
calls one; add the name to `reports/names.json` first. Constructors, operators and templates keep their
address names for now.

In the portal, a matched function shows how many things are left to name. **Ask the AI to name them**
sends the matched code to your own AI with the names known for what it calls; a version is kept only if
it still compiles to the same bytes and leaves fewer things to name. Read the names before you submit
them: the bytes are proven, the names are a person's (or an AI's) judgement.
