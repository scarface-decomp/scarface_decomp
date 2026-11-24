# SPEC-014: engine functions that kept their 2003 shape, and the public libraries inside the engine

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-24.
**Outside material read:** the leaked development tree of *The Simpsons: Hit & Run* (2003), on the founder's
computer: its Xbox release program and link map (only to find where each 2003 function starts and which
library it belongs to, so the two programs could be compared function by function), and, for §2, the source
of the context's state-stack functions. No name from that tree appears below except where Scarface's own
run-time type information or text carries the same name.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
that tree or anything built from it. Every fact below has a Scarface address you can check.

## 0. How close the shared libraries are (summary of the measurement)

Each Scarface function of 24 bytes or more was compared with every function of the 2003 Xbox release
program: first for an identical instruction shape (mnemonics and operand kinds, registers and addresses
masked), then, for a random sample, by the similarity of the mnemonic sequences to the closest 2003
function of the matching library. Scarface's game code, which is new, gives the noise floor: 16–18 % of its
functions score 0.8 or more by chance.

| Scarface layer | identical shape | sample ≥ 0.8 (no float code) | sample ≥ 0.8 (float code) | verdict |
| :--- | ---: | ---: | ---: | :--- |
| core (`core::`) | 27 % | 48 % | — | close copy |
| backend (`pure3d::d3d…`, `pure3d::pddi…`) | 3 % | 60 % | 8 % | close copy, except float code |
| drawing (other `pure3d::`) | 2 % | 25 % | 0 % | changed; near noise |
| front end, sound, physics, content, math, movie, `fight::` | 0–21 % | 0–24 % | 0 % | different code or noise |
| game code (control) | 4 % | 18 % | 0 % | noise floor |

Float code never resembles its 2003 counterpart: the 2003 engine libraries were built with `/arch:SSE`,
and Scarface's are not (SPEC-013 §5), so every float expression compiles differently. Shared class
names agree: of the classes with virtual tables, drawing shares 93 names with the 2003 engine, backend 32 and
core 33; the audio, physics, front-end and `fight::` classes share almost none. Where a class is shared,
Scarface's table is usually longer (drawing +2.7 slots on average, backend +4.8, core +2.0), so the
interfaces grew.

## 1. Public libraries inside the engine: no clean room needed

Three of the engine's components are published, licensed source. They come in under PROVENANCE.md's
"public, licensed material": vendor the exact public release with its licence, credit it, compile it with
the engine libraries' switches (no `/arch:SSE`), and match. None of this needs the 2003 tree.

| Component | Witness in `default.xbe` | Where the code is | Open now |
| :--- | :--- | :--- | :--- |
| **libpng 1.2.8** | `.rdata` 0x3D91D0 and 0x3DAF38: `"1.2.8"`; 0x3DB149: `"libpng version in application and library"`; the libpng messages listed in SPEC-013 §1; `png_memcpy_check` and `png_memset_check` are already in names.json | 0x2B8B00–0x2BE300 (50 functions) and, mixed with zlib, 0x2C9300–0x2CD600 (41) | 36 + 36 functions, 22,432 + 16,176 bytes |
| **zlib 1.2.1** (inflate side) | `.rdata` 0x3DF690: `" inflate 1.2.1 Copyright 1995-2003 Mark Adler "`; `adler32` already credited | 0x2C6400–0x2C7F00 (21) | 14 functions, 6,725 bytes |
| **Doug Lea's malloc, 2.7 series** (public domain) | the classes `core::MemoryDlAllocator` (vtable 0x3D8924) and `core::MemorySmallDlAllocator` (0x3D8974) | 0x28E190–0x28F5B0 (51) | 35 functions; the largest are 0x28ED30 (1,184 B), 0x28F1D0 (528 B), 0x28F460 (336 B) |

Notes for matching:

* The version strings settle libpng and zlib exactly. The allocator carries no version text; try 2.7.0,
  2.7.1 and 2.7.2 and keep the one whose functions match. Its configuration (which features are compiled
  in) is not known; read it from the code (for example, whether the allocator locks, and the alignment it
  uses).
* Compile the libraries as C (`.c` files), not C++. Use the engine-library flags from SPEC-013 §5
  (`/arch:SSE` off).
* Which public function each Scarface address is will come out of the compile-and-compare. This spec
  deliberately gives no per-address names for these libraries.
* Record each match's licence in CREDITS.md (libpng licence, zlib licence, public domain for the allocator).

## 2. The render context's state stacks (backend)

**Classes, all named in Scarface's run-time type information:** `pure3d::pddiBaseContext` (vtable 0x3D9A2C)
and `pure3d::d3dContext` (0x3D6B9C); `pure3d::pddiStack<pure3d::pddiViewState>`, `…<pddiRenderState>`,
`…<pddiLightingState>`, `…<pddiFogState>`, `…<pddiStencilState>`; and the five state classes
`pure3d::pddiViewState`, `pddiRenderState`, `pddiLightingState`, `pddiFogState`, `pddiStencilState`.

**Two functions,** in both vtables at the same slots:

| Slot | Function | Size | Status |
| ---: | :--- | ---: | :--- |
| 99 | 0x29F160 | 432 B | open |
| 100 | 0x29E8E0 | 240 B | open |
| (helpers) | 0x29E9D0 (96 B), 0x29EA30 (192 B) | | open |

### 2.1 Layout (from the two functions' own loads and stores)

The context holds five stack pointers, then five current-state pointers:

| Offset | Holds |
| :--- | :--- |
| +0x138 | stack of view states |
| +0x13C | stack of render states |
| +0x140 | stack of lighting states |
| +0x144 | stack of fog states |
| +0x148 | stack of stencil states |
| +0x14C | pointer to the current view state |
| +0x150 | pointer to the current render state |
| +0x154 | pointer to the current lighting state |
| +0x158 | pointer to the current fog state |
| +0x15C | pointer to the current stencil state |

Each `pddiStack<T>` object is laid out as follows:

* +0: vtable pointer. The class has a virtual destructor.
* +4: capacity.
* +8: index of the top element.
* +0xC: pointer to an array of `T`.

Three small members are written in the class body, so every caller expands them:

* **Top:** returns `&array[top]`.
* **Push:** `++top;` then `array[top] = array[top - 1];`. This is an assignment, so the destination's
  vtable pointer is never written. That is why the copies start at +4.
* **Pop:** `--top;`.

Each state class starts with a vtable pointer. Its one virtual function, slot 0, takes the context as its
only argument (see 2.3). The members, by offset:

| Class | Size | Members after the vtable pointer |
| :--- | ---: | :--- |
| render | 0x1C | dword +4, bool +8, dword +0xC, bool +0x10, dword +0x14, four bools +0x18…+0x1B |
| view | 0x34 | four dwords +4…+0x10; a 16-byte member at +0x14; a 16-byte member at +0x24 (each copied as four dwords from its own base: two small classes or structs) |
| lighting | 0x3EC | an array of 8 members of 0x7C bytes each at +4 (each copied as 31 dwords: plain data); then dwords at +0x3E4 and +0x3E8 |
| fog | 0x14 | bool +4, dwords +8, +0xC, +0x10 |
| stencil | 0x24 | bool +4, seven dwords +8…+0x20 |

The compiler generates the assignment operators; don't write them. For render, fog and stencil it expands
them inline. For view and lighting it emits them out of line, as 0x29E9D0 and 0x29EA30 (both `ret 4`,
`this` in ECX, source pointer on the stack). 0x29EA30's eight `rep movsd` blocks are the element-wise copy
of the 8-element member array; the two dwords that follow are the last members.

### 2.2 Slot 99 (0x29F160)

* **Signature:** one stack argument, a bit mask. It cleans 4 bytes (`ret 4`) and returns nothing.
* **Body:** five independent `if` blocks, one per bit, in this order:
  1. `0x01`: render stack.
  2. `0x02`: view stack.
  3. `0x04`: lighting stack.
  4. `0x08`: fog stack.
  5. `0x10`: stencil stack.
* **Each block:** push that stack, then store that stack's top-element pointer in the matching
  current-state member.

Codegen notes:

* The mask is read once into BL (`mov bl, [ebp+8]`), with a `test bl, imm` per block.
* The function keeps an EBP frame (`push ebp; mov ebp, esp`), as the other backend functions do.
* Each block reloads the stack pointer from `this` after the push. Source that writes
  `m_renderState = m_renderStack->Top();` after `m_renderStack->Push();` gives exactly that.
* The array index is scaled by the element size: `imul 0x1C`, `0x34`, `0x3EC`; `lea` forms for 0x14 and
  0x24.

### 2.3 Slot 100 (0x29E8E0)

* **Signature:** the same mask argument; `ret 4`.
* **Bits:** tested in the same order as slot 99.
* **Each block:**
  1. Pop the stack (`dec dword [stack+8]`).
  2. Reload the stack and store its top pointer in the current-state member.
  3. Make a virtual call through slot 0 of the new current state, with the context (`this`) pushed as
     the argument and ECX = the state.

### 2.4 Where Scarface differs from 2003 (facts about Scarface)

* The view state is 0x34 bytes; it holds four dwords and two 16-byte members.
* The lighting state puts its 8-element array first and its two single dwords last (+0x3E4, +0x3E8).

## 3. Open engine functions with a close 2003 counterpart

These open functions score 0.8 or more against the closest 2003 function of the same library, above the
noise floor in §0. Their structure is old engine code. Expect straightforward control flow, and expect
the class layouts to be shared with already-matched neighbours. The role is in the examiner's own words.

| VA | Size | Similarity | Scarface class (RTTI/registry) | Role |
| :--- | ---: | ---: | :--- | :--- |
| 0x29F160 | 432 | 0.99 | `pure3d::pddiBaseContext` | §2 |
| 0x29E8E0 | 240 | 0.98 | `pure3d::pddiBaseContext` | §2 |
| 0x29BE70 | 976 | 0.89 | (backend) | constructor of the object that owns the vertex programs; takes the D3D context |
| 0x29B1A0 | 960 | 0.81 | `pure3d::d3dDisplay` | sets up the display and the D3D device from an init structure |
| 0x29B670 | 736 | 0.83 | (backend) | fills a lock-description structure from a D3D surface format (switch on format) |
| 0x299850 | 720 | 0.89 | `pure3d::d3dTexture` | creates a 2-D texture (width, height, depth/bpp, mip count, type, usage) |
| 0x299B20 | 656 | 0.92 | `pure3d::d3dTexture` | creates a volume texture (as above, plus depth) |
| 0x299E20 | 288 | 0.93 | `pure3d::d3dTexture` | locks a mip level / rectangle and returns the lock description |
| 0x299650 | 272 | 0.97 | `pure3d::d3dTexture` | constructor from the context and an existing D3D texture |
| 0x29A060 | 272 | 0.97 | `pure3d::d3dTexture` | constructor from the context |
| 0x25DA60 | 272 | 0.88 | (drawing range) | a second texture constructor, same shape as 0x29A060 |
| 0x2AD790 | 304 | 0.90 | `pure3d::d3dPrimBuffer` | draws the buffer |
| 0x2AD3B0 | 256 | 0.85 | (`pure3d::d3dPrimBufferStream`) | sets the stream's base pointer and vertex program |
| 0x2C3CF0 | 320 | 0.86 | `pure3d::d3dShadowShader` | sets up one render pass |
| 0x2C1C60 | 256 | 0.97 | `pure3d::d3dErrorShader` | sets up one render pass |
| 0x2AE020 | 288 | 1.00 | (lib) | one-time shader setup (no arguments) |
| 0x2C0210 | 624 | 0.97 | `core::XboxSaveDrive` | creates/opens the save file in a save container |
| 0x2BFB50 | 416 | 0.95 | `core::XboxSaveDrive` | constructor (drive name, priority) |
| 0x2C0760 | 416 | 0.91 | `core::XboxSaveDrive` | reads one block of the save file |
| 0x2C1180 | 384 | 0.80 | `core::XboxSaveDrive` | starts a directory search |
| 0x2BFF10 | 288 | 0.87 | `core::XboxSaveDrive` | mounts the save container |
| 0x2C0100 | 272 | 0.90 | `core::XboxSaveDrive` | writes the pending block |
| 0x2BFE10 | 256 | 0.81 | `core::XboxSaveDrive` | translates a system error code into the drive's error enum (switch) |
| 0x2BEEC0 | 528 | 0.85 | `core::XboxDrive` | constructor (drive name, priority) |
| 0x2BF120 | 368 | 0.96 | `core::XboxDrive` | opens a file |
| 0x2AC8C0 | 272 | 0.91 | `core::Drive` | services the request queue once |
| 0x2AB470, 0x2AB570 | 256 each | 0.85, 0.81 | `core::File` | the two constructors (drive, name, flag, open mode, …) |
| 0x2ABDB0, 0x2ABEC0 | 208 each | 0.82, 0.81 | `core::InstanceDrive` | the asynchronous file-open and save-open entry points |
| 0x2479F0 | 240 | 0.84 | `core::ControllerXBox` | polls the pad |
| 0x26CC30 | 832 | 0.94 | (drawing) | builds a sprite's texture from an image region |
| 0x26DE40 | 688 | 0.88 | (drawing) | splits a sprite image into texture sections |
| 0x298D00 | 528 | 0.93 | `pure3d::ImageConverter` | copies an image into a locked texture |
| 0x298630 | 400 | 0.81 | `pure3d::ImageConverter` | builds a volume texture from an image array |
| 0x298A40, 0x298B50, 0x2988A0, 0x298970 | 272, 224, 208, 208 | 0.89–0.92 | (drawing) | pixel-format converters (32→32, generic→32, 32→16, generic→16) |
| 0x297F40 | 512 | 0.92 | `pure3d::PNGHandler` | creates an image from a PNG file |
| 0x297C60, 0x297E00 | 416, 320 | 0.97, 0.92 | (drawing) | PNG row loaders for 4-bit and 8-bit images |
| 0x298230 | 448 | 0.85 | (drawing) | loads a DXT-compressed image file |
| 0x26C6F0, 0x26C840 | 336, 288 | 0.94, 0.93 | (drawing) | BMP loaders for 4-bit and 8-bit images |
| 0x261440, 0x2612E0 | 368, 320 | 0.82, 0.84 | (drawing) | Targa loaders, colour-mapped and true-colour |
| 0x262020, 0x261EE0 | 368, 320 | 0.88, 0.92 | `pure3d::TextureBuilder` | processes one 8-bit / 32-bit scanline |
| 0x261920 | 256 | 0.81 | `pure3d::ImageBuilder` | begins an image (width, height, depth, origin) |
| 0x263B00 | 352 | 0.91 | `pure3d::Image32` | copies a region from another image |
| 0x263350 | 224 | 0.85 | (`pure3d::Image8` range) | resizes the image |
| 0x2636E0 | 304 | 0.95 | (drawing) | block copy of 32-bit pixels with a mask colour |
| 0x27D030 | 416 | 0.89 | `pure3d::ImageFont` | draws one line of text into an image |
| 0x28B0F0 | 352 | 0.84 | `pure3d::DefaultChannelHandler` | loads one animation channel from a chunk file |
| 0x2AF370 | 208 | 0.83 | (`pure3d::VertexList`) | destructor |
| 0x252DF0 | 368 | 0.90 | (math range) | sets a spline's control mesh from a basis and four points |

The rest of the 81 functions that score 0.8 or more are in the public libraries of §1.

## 4. Next

* §2 is complete for its two functions.
* The next entries, if wanted, are the `core::XboxSaveDrive` group (seven functions, 0.80–0.97). It is the
  closest copy and one class.
* After that come the `pure3d::d3dTexture` group (five).
