# The game's scripts (.cso, .dso, .dtr)

Besides its C++ code, Scarface runs scripts. They were written in **TorqueScript**, a C++-like
scripting language, and shipped compiled: `.cso` and `.dso` files are compiled scripts and `.dtr`
files go with them. All of them are packed in `scriptc\` inside `cement.rcf`.

They get the same treatment as the C++: a version people can read, which is only counted when it is
proven to turn back into **exactly the same bytes** as the game's file. Nothing is counted on looks.

## What's in the files

The scripts are the same on every console: the 650 script files in the Xbox disc's `cement.rcf` and
the PS2 disc's `CEMENT.RCF` are byte-identical (compared 2026-11-08), and the set includes the PC's own
scripts. So any one of these discs gives you all of them.

The April 2006 Xbox prototype is different: 506 `.cso`, 358 `.dso` and 31 `.cs` files, so it has scripts the
finished game doesn't. The portal's Game Scripts tab shows each version separately and marks every
prototype file as the same as retail, changed, or only in the prototype.

From the PS2 disc's `CEMENT.RCF` (4,764 files), checked on 2026-11-08:

* **400 `.cso` and 235 `.dso`**: compiled TorqueScript, all version 1. They include the PC's own
  scripts (for example `scriptc\actionmaps_Win32.cso` next to `actionmaps_PS2.cso`).
* **14 `.cs`**: plain TorqueScript source that was left in the archive, small level-art scripts
  such as `Renderer_PropCreateBegin("tonymansion_04_shell.p3d", "1");`. Useful as known examples.
* **1 `.dtr`**: `ai\common.dtr` (28 KB), the AI's decision tree (its layout is below).

## Where things stand

| Step | Status |
|---|---|
| 1. Get the files out of your own copy | **Done**: the portal does it each time it starts, for every game download in `binaries/` it hasn't done yet; by hand: `python portal/scripts/extract_scripts.py <source>`, where the source is the Xbox `.7z` or disc image, the PS2 `.iso`, the prototype `.zip`, or `cement.rcf` from an installed PC game. Each version goes in its own folder under `binaries/scripts_and_data/` (never committed). The PC disc keeps its files inside `DATA*.CAB`, so for the PC use `cement.rcf` from the installed game. |
| 2. Read the compiled format exactly and write it back byte for byte | **Done**: `portal/tools/torque_dso.py`. All 635 compiled scripts round-trip exactly. |
| 3. Turn the bytecode into readable TorqueScript | **Done**: `portal/tools/torque_script.py`. Every one of the 635 compiled scripts decompiles. |
| 4. Compile readable TorqueScript back to the original bytes, and only then count the script | **Done**: the same tool compiles the text again, laid out exactly as the game's compiler does, and compares. **All 635 retail scripts come back byte for byte, and all 864 of the April 2006 prototype's.** |
| 5. Work out what `.dtr` files are | **Mostly done**: `portal/tools/dtr_format.py` reads the decision tree and rebuilds it byte for byte; the tree, its 58 AI task names and labels are readable. The small programs inside the nodes are still listed as numbers. |
| 6. Recover the names | **About half done**: see "Names" below. |

The portal's Game Scripts tab shows each file as TorqueScript, says whether it compiled back exactly,
and lists the instructions next to it. From the command line:

```
python portal/tools/torque_script.py decompile binaries/scripts_and_data/xbox --out decompiled_scripts
python portal/tools/torque_script.py compile mine.cs -o mine.cso    # add --style ste for the prototype
```

`decompile` writes one `.cs` file per script (keeping the folders) and reports how many compiled back
exactly; `compile` turns a `.cs` file into a `.cso` the game can load. Keep the output outside the
repository, or under `binaries/` (never committed): it is the game's code.

### How it works

* `torque_decompile.py` runs the bytecode on a model of Torque's virtual machine whose stacks hold
  pieces of source instead of values, and recognises the shapes the compiler emits for `if`, loops,
  `&&`, `||`, `?:`, objects and the rest.
* `torque_print.py` writes that as TorqueScript; `torque_parse.py` reads TorqueScript.
* `torque_compile.py` compiles it again following Torque's two passes: precompile fills the string,
  number and name tables in the compiler's order, then compile writes the code. Scarface's own
  differences: 2-code numbers and names, separate opcodes for `%local` and `$global` variables, the code
  padded to an even length with `0xCDCD`, tagged strings stored in 7 bytes, and words that are not
  numbers turning into NaN when compared as numbers (`default.xbe` 0x00068E60).
* The April 2006 prototype's compiler was a slightly different build: it writes names as `ste` +
  decimal, leaves zeros or leftover memory instead of `0xCD` (the decompiled text keeps the one padding
  code it needs as a `// compiler padding: 0x....` line), and adds the right side of a comparison or
  `&&`/`||` to the tables before the left. `compile --style ste` copies it.

### Names

The game stores every name (functions, variables, fields, classes) as a hash: `stx` plus 8 letters,
for example `stxipcpjjln`. It is Radical's 65599 string hash, case-insensitive (`default.xbe`
0x00243FA0; 0x00076760 turns the letters back into the number); variables are hashed with their `%`
or `$`. The April 2006 prototype writes the same number in decimal (`ste3684299512`).

A hash can't be reversed, but a word can be checked. The tool hashes every word in your game's
executables and the scripts' own strings; where one matches, the word is shown. That recovers about
half the names (6,617 of 12,893 in the retail scripts, 61% of uses), mostly the engine's own: classes,
fields and functions such as `FindObject`, `MainCharacter`, `%count`. The rest, mainly names the
scripts made up themselves, stay as their hash; they compile to the same bytes. Better word lists
are welcome.

`python portal/tools/hash_names.py binaries/` goes further and writes `reports/hash_names.json`: it also
reads the other game files that hold names as text, the script commands and class fields the program
registers, and the project's own names. Then it makes up texts and keeps the ones that land on a key:
two known words joined, and a known name with another number in it (the scripters numbered missions,
waves and slots in runs, and only part of a run is spelled out in the game's data: `S02_01` is there,
so `S02_03` and `S10_01` are tried). Made-up texts are marked as not certain, and the report says how
many of them to expect by chance. That names 9,529 of the 15,177 keys the scripts of the retail games
and the prototype use.

Gangsta Team's [RCF explorer](https://gangsta-team.github.io/web-rcf-explorer/) has a word list of its
own for these keys. It was compared with ours on 25 November 2026: every one of the 4,031 keys both
name has the same text. It names 154 keys we don't (sound locations, front triggers, door groups),
none of them a text found in the game files the tool reads. Those names are not in this repository:
the list has no licence file and doesn't say where its texts come from, and
[PROVENANCE.md](PROVENANCE.md) asks for both. If they are names of objects in the game's own `.p3d`
and sound files, which the tool doesn't read for names yet, reading those is the way to get them from
your own copy.

### Script commands only the PC game has

The Xbox game registers 820 script commands (`reports/script_bindings.json`). Gangsta Team's
[natives list](https://gangsta-team.github.io/website/#/documentation/game/natives) for the PC game
(public domain) has all 820, with the same class, name and return type and, but for
`GameSimObject::SetInvincible` (3 arguments on the Xbox, 3 or 4 on the PC), the same argument counts.
It also has 34 the Xbox game doesn't register, the PC's own settings and input:

* display: `ChangeResolution`, `SaveResolutionChangeToRegistry`, `GetDisplayWidth`, `GetDisplayHeight`,
  `ChangeMSAA`, `GetMSAA`, `GetMaxMSAACaps`, `ChangeBrightness`, `GetBrightness`, `SetAnisValue`,
  `GetAnisotropicValue`, `SetTrilinear`, `IsTrilinearEnabled`, `SetDrawDistance`, `GetDrawDistance`,
  `GetVideoCardLevel`, `EnableSFX`, `SFXEnabled`;
* keys and mouse: `ApplyEventInputChanges`, `UpdateInputPoint`, `GetInputPointByName`,
  `GetInputPointByLogicalName`, `GetDisplayNameByInputPoint`, `GetPhysicalOverride`,
  `ClearPhysicalOverride`, `SetMouseSensitivityLevel`, `GetMouseSensitivityLevel`, `SetIsLeftHand`,
  `GetIsLeftHand`, `ActionMap::BindCommandNoOverride`, `PauseMenuPageControllerConfig::Input`;
* others: `call`, `CanLegendBeUnshown`, `ResetLastDriveError`.

Their functions are in the part of `Scarface.exe` that can't be read from the file
([GAME_VERSIONS.md](GAME_VERSIONS.md)), so none of them is in the work queue.

### `.dtr`: the AI decision trees

`ai/common.dtr` (the engine's `DecisionTreeFileHandler`) is a tree of 319 nodes. Each leaf runs an
AI task (`AITask_Engage`, `AITask_FleeFromCops`, ... all 58 names recovered by their hash), and nodes
carry up to four small programs. The layout is in `portal/tools/dtr_format.py`. Still open: what the
four program slots are for, and the program words. Observations so far: a program is a list of small
numbers; `26` ends one, `24 0` / `24 1` just before it look like "false" / "true", and `22` is followed
by a 32-bit float (`1101004800` is 20.0).

Why TorqueScript and not plain C++? The scripts were written in TorqueScript, so that is the only
language that can be compiled back to the exact original bytes. It reads much like C++ (functions,
`if`, `while`, `for`, variables), so anyone who can read the C++ side can read it.

## The 1:1 rule for scripts

A script counts as done only when:

1. the readable version compiles back to a file that is **byte-identical** to the game's `.cso`/`.dso`;
2. it is ordinary TorqueScript, not a hex dump or a list of raw bytes;
3. it was checked by the tool, not by eye.

## Help wanted

* Names: lists of words, or knowledge of what the scripts call things, recover more of the hashed
  names. A guessed word is only used when its hash matches, so trying more words is safe.
* The `.dtr` programs: reading the interpreter behind `DecisionTreeFileHandler` in the executable.
* Run step 1 on the PC version and compare with the PS2 files: identical files only need doing once.
