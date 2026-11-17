// bin: xb
// va: 0x00162490
// tool: the portal's starter code (no AI)
// sub_00162490 (0x00162490, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00162490(int a1, bool a2, float a3)
{
    *(bool*)a1 = a2;
    *(float*)(a1 + 4) = a3;
    return a1;
}
