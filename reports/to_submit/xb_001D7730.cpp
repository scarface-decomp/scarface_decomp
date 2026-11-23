// bin: xb
// va: 0x001D7730
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7730 (0x001D7730, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_001D7730(int a1)
{
    int t1;

    t1 = *(int*)(a1 + 48);
    if (*(int*)(a1 + 48)) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
