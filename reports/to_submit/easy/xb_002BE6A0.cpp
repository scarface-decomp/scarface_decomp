// bin: xb
// va: 0x002BE6A0
// tool: the portal's starter code (no AI)
// sub_002BE6A0 (0x002BE6A0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_00461A58;
extern "C" int DAT_00461A5C;

int __cdecl sub_002BE6A0(int a1, int a2)
{
    DAT_00461A58 = a1;
    DAT_00461A5C = a2;
    return a1;
}
