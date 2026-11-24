// bin: xb
// va: 0x001D6F00
// what: 
// tool: the portal's starter code (no AI)

// sub_001D6F00 (0x001D6F00, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001D79E0(void);

int __cdecl sub_001D6F00(void)
{
    int t1;

    t1 = sub_001D79E0();
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
