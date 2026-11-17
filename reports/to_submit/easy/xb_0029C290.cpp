// bin: xb
// va: 0x0029C290
// tool: the portal's starter code (no AI)
// sub_0029C290 (0x0029C290, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int DAT_0045EAB4;
extern "C" int DAT_0045EAB8;

int __cdecl sub_0029C290(int a1, int a2)
{
    DAT_0045EAB4 = a1;
    DAT_0045EAB8 = a2;
    return a1;
}
