// bin: proto
// va: 0x00066B00
// what: 
// tool: the portal's starter code (no AI)

// sub_00066B00 (Proto 0x00066B00, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000660B0(void);

int __cdecl sub_00066B00(void)
{
    int t1;

    t1 = sub_000660B0();
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
