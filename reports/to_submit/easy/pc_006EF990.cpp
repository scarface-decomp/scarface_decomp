// bin: pc
// va: 0x006EF990
// tool: the portal's starter code (no AI)
// sub_006EF990 (0x006EF990, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EF990(int a1, int a2)
{
    *(int*)(a1 + 32) = a2;
    return a2;
}
