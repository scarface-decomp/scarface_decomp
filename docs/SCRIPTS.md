# The game's scripts (.cso, .dso, .dtr)

Besides its C++ code, Scarface runs scripts. They were written in **TorqueScript**, a C++-like
scripting language, and shipped compiled: `.cso` and `.dso` files are compiled scripts and `.dtr`
files go with them. All of them are packed in `scriptc\` inside `cement.rcf`.

They get the same treatment as the C++: a version people can read, which is only counted when it is
proven to turn back into **exactly the same bytes** as the game's file. Nothing is counted on looks.

## Where things stand

| Step | Status |
|---|---|
| 1. Get the files out of your own `cement.rcf` | **Ready**: `python scripts/extract_scripts.py path\to\cement.rcf` writes them to `binaries/scripts_and_data/` (never committed). |
| 2. Read the compiled format exactly (header, string and float tables, bytecode, identifier table) and write it back byte for byte | Started: `tools/script_formats.py` checks this round trip. It still has to be confirmed on the real files. |
| 3. Turn the bytecode into readable TorqueScript | Needs the real files; the format is documented by Broken Face (see Credits). |
| 4. Compile readable TorqueScript back to the original bytes, and only then count the script | To do. This is the script equivalent of Compile & Verify. |
| 5. Work out what `.dtr` files are | To do. The game refers to `.dtr` next to its script folders (`scriptc/`, `resources.ds`). |

Why TorqueScript and not plain C++? The scripts were written in TorqueScript, so that is the only
language that can be compiled back to the exact original bytes. It reads much like C++ (functions,
`if`, `while`, `for`, variables), so anyone who can read the C++ side can read it.

## The 1:1 rule for scripts

A script counts as done only when:

1. the readable version compiles back to a file that is **byte-identical** to the game's `.cso`/`.dso`;
2. it is ordinary TorqueScript, not a hex dump or a list of raw bytes;
3. it was checked by the tool, not by eye.

Progress for scripts will be kept in its own registry and shown on the website next to the C++
progress once step 4 exists.

## Help wanted

* Run step 1 on your copy (PC, Xbox or PS2) and report how many files each kind has.
* Compare the PC, Xbox and PS2 scripts: identical files can be done once.
* Anyone who knows TorqueScript's compiler (Torque Game Engine 1.x) is especially welcome on step 4.
