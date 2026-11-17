// bin: xb
// va: 0x0029F7B0
// tool: the portal's starter code (no AI)
// sub_0029F7B0 (0x0029F7B0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" bool DAT_004BDC80;

bool __cdecl sub_0029F7B0(bool a1)
{
    DAT_004BDC80 = a1;
    return a1;
}
