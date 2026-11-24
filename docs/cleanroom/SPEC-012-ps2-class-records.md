# SPEC-012: the PS2 program names its own classes

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-23.
**Outside material read:** the PS2 notes of the extended *scarface-p3d* research (they describe the European
PS2 program). They said the records exist and roughly where; every layout, count and address below was then
read from the founder's own **US** PS2 program, `SLUS_211.11`, and from his own `default.xbe`.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
the research.

The repository's PS2 tools say "the PS2 program has no names". It has: the program carries a record for
every class that has virtual functions, with the class's name as plain text and the list of its ancestors,
and every virtual table points at its class's record. That turns the PS2's virtual tables from anonymous
runs of function addresses into named classes, without borrowing anything from the Xbox game.

All numbers are little-endian 32-bit words. Addresses are the US program's.

## 1. Where the records are

The program is one ELF file. Its code comes first; the class records and the virtual tables sit in the data
that follows it. In the US program the lowest class-name text is at `0x0078C928`; nothing below that address
is a record, and no virtual function is at or above it.

## 2. A class record (8 bytes)

| word | what it holds |
| :--- | :--- |
| 1 | the address of the class's name, a zero-ended text |
| 2 | the address of the class's ancestor list, or `0` when the class has no ancestors |

The name is the ordinary C++ spelling, with namespaces and with template arguments written out:
`renderer::WorldGeoRenderable`, `pure3d::ps2Context`, `CScript::Method1<void, EExitVehicleParam>`,
`CScript::Function2<ScriptObject *, const char *, unsigned int>`.

## 3. An ancestor list

A run of 8-byte entries, each the address of an ancestor's class record followed by a zero word, ended by an
entry of two zero words.

* The list holds **every** ancestor, the most distant first. `renderer::WorldGeoRenderable`'s list is
  `core::IRefCount`, `content::LoadObject`, `pure3d::Entity`, `renderer::Renderable`.
* The direct parent can be told from the list alone: it is the entry whose own ancestor list is exactly the
  entries before it. That holds for all 2,238 classes that have ancestors. For 2,150 of them the parent is
  the last entry. The other 88 have more base classes after the parent (multiple inheritance):
  `CharacterObject`'s list is `ConsoleObject`, `ScriptObject`, `GameSetObject`, `GameObject`,
  `GameSimObject`, `InventoryOwner`.
* 485 records have no ancestors.

For one class the three pieces lie together in this order: the name text, the ancestor list, the record.
(`renderer::WorldGeoRenderable`: name at `0x007B72C0`, list from `0x007B72E0`, record at `0x007B7308`.)

## 4. A virtual table

| word | what it holds |
| :--- | :--- |
| 1 | the address of the class record |
| 2 | `0` for the class's main table; a small negative number for a table that belongs to a second base class inside the object (see §6) |
| 3 onwards | one function address per virtual function, in declaration order |

**An object's first word holds the address of word 1**, not of the first function. Checked: the code
builds the address of a main table's first word in 7,274 places (an upper-half load followed by an add or
an or of the lower half) and never the address 4 or 8 bytes on. So virtual function number *k* (counting
from 0) is at *table address + 8 + 4k*.

Examples (US):

| class | record | main table | virtual functions |
| :--- | :--- | :--- | :--- |
| `renderer::WorldGeoRenderable` | `0x007B7308` | `0x007F07B0` | 16 |
| `renderer::Renderable` | `0x007B6680` | `0x007F0660` | 16 |
| `renderer::WorldGeoLoader` | `0x007B72B8` | `0x007F0780` | 7 |
| `ScriptObject` | `0x0078D010` | `0x007EF8D0` | 29 |
| `CharacterObject` | `0x0078D998` | `0x007DE510` | 74 |
| `pure3d::ps2Context` | `0x007CDE10` | `0x007FD930` | 133 |

`ScriptObject` has 29 virtual functions on the Xbox too. `WorldGeoRenderable`, `Renderable` and
`WorldGeoLoader` start with the same three functions (`0x003929D0`, `0x003929E0`, `0x00392A90`), as classes
under `core::IRefCount` share their first three on the Xbox. Whether the numbering lines up between the two
programs class by class is for the implementer to measure (§7), not to assume.

## 5. How many

Read by shape from the US program (a record is two words where the first points at a text that reads as a
class name and the second is `0` or points at a well-formed ancestor list whose entries are all records):

* 2,723 records, 2,482 different names. Some classes have more than one record (`ScriptObject` has three);
  only one of them is pointed at by a table. Treat records with the same name as the same class.
* About 40 of those names are not names (`HUy`, `P:z`, `WMA `): two data words that happen to fit. A name
  must be in the record area, be at least four characters, and be made of identifiers joined by `::` with an
  optional `<…>` part. No table points at any of the stray ones.
* 2,293 main tables, for 2,291 classes. 432 records have no table (classes that are only ever a base, and
  the duplicates).
* 159 further tables whose second word is a small negative number (−4 to −796; −104, −4 and −84 are the
  commonest).

## 6. Tables for a second base class

When a class has more than one base class with virtual functions, the object holds a second table pointer
further in. That table's first word is the same class record and its second word is a negative number.
Reading: it is the distance from that inner pointer back to the start of the object. That reading fits the
values but was **not checked** against code; the implementer should confirm it on one class (a function in
such a table should begin by moving its object pointer back by that amount, or the table should hold small
forwarding functions) before relying on it.

## 7. What it is for

1. **Every PS2 virtual function gets its class and its place** (`Class`, function number), from the PS2
   program alone. `portal/tools/ps2_pairing.py` no longer has to bootstrap tables from shared strings.
2. **Pairing with the Xbox by name.** The Xbox program's type information gives the same class names in its
   own encoded spelling. Comparing plain names (no templates): the Xbox has 1,601, the PS2 2,482, and 1,465
   are on both. Templates need the Xbox spelling decoded to the PS2's (`?$Method1@XW4EExitVehicleParam@@@CScript@@`
   is `CScript::Method1<void, EExitVehicleParam>`); the repository's `script_typed.py` already decodes that
   family.
3. **A check on the pairing.** For a class on both, compare the number of virtual functions and, where both
   functions are already paired by other evidence, that they sit at the same number. Record the classes where
   the two programs disagree: those are where a platform added or dropped a virtual function (`pure3d::ps2Context`
   has 133, the Xbox's `pure3d::d3dContext` 132; they are different classes, but their shared ancestors
   should agree).
4. **PS2-only classes** (about 1,000 names not on the Xbox, many of them template spellings) are named for
   the first time: the PS2 renderer (`pure3d::ps2Context` and its family), and whatever the PS2 build kept
   that the Xbox build dropped.
5. **Chunk readers.** Each chunk reader object's class is now readable: follow the reader's table to its
   record. That gives, for the PS2, the same chunk-id → reader-class table the repository has for the Xbox.
6. **Typed script functions.** The `CScript::Method…`/`Function…` classes are here with readable
   signatures, so the typed registrations can be read on the PS2 as on the Xbox.

## 8. Work items

1. A reader in `portal/tools/` that returns, for a PS2 program: records (address, name, ancestors, parent),
   main tables (address, record, functions) and second-base tables (address, record, offset). Reject by the
   rules in §5. Tests against the numbers in §5 and the examples in §4, skipped when the program is absent.
2. Use it in `ps2_pairing.py`: pair tables by class name first; keep the existing evidence as the check in
   §7.3. Report how many PS2 functions gain a `Class::vfunc_NN` name and how many disagreements were found.
3. Names: a PS2 function's class name comes "from the PS2 program's own class record"; record that as the
   source. No name from the research is involved.
4. Confirm or correct §6.
5. Say in the PS2 tools' own text that the program does carry class names.

## 9. What was not looked at

* Whether the PS2 prototype or the overlays carry the same records.
* Classes with no virtual functions: they have no record.
* The European program: the notes describe it; the US one was read instead, and the project accepts US
  versions only.
