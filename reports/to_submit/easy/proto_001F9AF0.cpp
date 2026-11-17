// bin: proto
// va: 0x001F9AF0
// tool: the portal's starter code (no AI)
// sub_001F9AF0 (0x001F9AF0, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCE40(int, int, int, int);

void __cdecl sub_001F9AF0(int a1, int a2, int a3)
{
    int t2;

    if (!*(bool*)(a1 + 16)) {
        sub_001FCE40(a1 + 17, 256, a2, (int)(&a3));
        t2 = *(int*)(a1 + 12);
        *(bool*)(a1 + 16) = true;
        *(int*)(a1 + 276) = t2;
    }
}
