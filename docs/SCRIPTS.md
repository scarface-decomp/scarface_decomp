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
* **1 `.dtr`**: `ai\common.dtr` (28 KB). Not a Pure3D chunk file; the format is still unknown, and
  the name suggests AI decision trees.

## Where things stand

| Step | Status |
|---|---|
| 1. Get the files out of your own copy | **Done**: `python scripts/extract_scripts.py <source>`, where the source is the Xbox `.7z` or disc image, the PS2 `.iso`, the prototype `.zip`, or `cement.rcf` from an installed PC game. Each version goes in its own folder under `binaries/scripts_and_data/` (never committed). The PC disc keeps its files inside `DATA*.CAB`, so for the PC use `cement.rcf` from the installed game. |
| 2. Read the compiled format exactly and write it back byte for byte | **Done**: `tools/torque_dso.py`. All 635 compiled scripts round-trip exactly. The portal's Scripts tab uses it. |
| 3. Turn the bytecode into readable TorqueScript | Next. The opcode set is Scarface's own (83 opcodes, 0 to 85), documented by Broken Face. |
| 4. Compile readable TorqueScript back to the original bytes, and only then count the script | To do. This is the script equivalent of Compile & Verify. |
| 5. Work out what `.dtr` files are | To do (one file so far). |

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

* Run step 1 on the PC and Xbox versions and compare with the PS2 files: identical files only need doing once.
* Anyone who knows TorqueScript's compiler (Torque Game Engine 1.x) is especially welcome on step 4.
