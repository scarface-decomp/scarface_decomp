// bin: proto
// va: 0x0019EF20
// what: 
// tool: the portal's starter code (no AI)

// sub_0019EF20 (Proto 0x0019EF20, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0019FA10(void);

int __cdecl sub_0019EF20(void)
{
    int t1;

    t1 = sub_0019FA10();
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
