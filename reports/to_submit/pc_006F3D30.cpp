// bin: pc
// va: 0x006F3D30
// what: 
// tool: the portal's starter code (no AI)

// sub_006F3D30 (PC 0x006F3D30, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006F3C90(int, int, int, int, int);

void __cdecl sub_006F3D30(int a1, int a2, int a3, int a4)
{
    sub_006F3C90(a1 + 12, *(int*)(a1 + 20) + (((((((unsigned int)*(int*)(a1 + 12)) >> 4) & 31) * a3) + a2) * 2), *(int*)(a1 + (a2 * 4) + 40), a3, a4);
}
