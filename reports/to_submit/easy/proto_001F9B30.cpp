// bin: proto
// va: 0x001F9B30
// tool: the portal's starter code (no AI)
// sub_001F9B30 (0x001F9B30, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001FCE40(int, int, int, int);

void __cdecl sub_001F9B30(int a1, int a2, int a3, int a4)
{
    if (!*(bool*)(a1 + 16)) {
        sub_001FCE40(a1 + 17, 256, a3, (int)(&a4));
        *(bool*)(a1 + 16) = true;
        *(int*)(a1 + 276) = a2;
    }
}
