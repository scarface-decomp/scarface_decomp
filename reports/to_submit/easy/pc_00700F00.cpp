// bin: pc
// va: 0x00700F00
// tool: the portal's starter code (no AI)
// sub_00700F00 (0x00700F00, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00700F00(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 4);
    if (*(int*)(a1 + 4)) {
        return t1 + -4;
    }
    return 0;
}
