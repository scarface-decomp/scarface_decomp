// bin: proto
// va: 0x00066AF0
// what: 
// tool: the portal's starter code (no AI)

// sub_00066AF0 (Proto 0x00066AF0, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00066090(void);

int __cdecl sub_00066AF0(void)
{
    int t1;

    t1 = sub_00066090();
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
