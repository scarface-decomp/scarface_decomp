// bin: pc
// va: 0x006FE7B0
// tool: the portal's starter code (no AI)
// sub_006FE7B0 (0x006FE7B0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006FE7B0(int a1)
{
    int t1, t2;

    t1 = *(int*)(a1 + 4);
    if (*(int*)(a1 + 4)) {
        t2 = *(int*)t1;
        *(int*)(a1 + 12) += 1;
        *(int*)(a1 + 4) = t2;
        return t1;
    }
    return 0;
}
