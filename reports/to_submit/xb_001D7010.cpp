// bin: xb
// va: 0x001D7010
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7010 (0x001D7010, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001D7D20(int);

int __cdecl sub_001D7010(int a1)
{
    int t1;

    t1 = sub_001D7D20(a1);
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
