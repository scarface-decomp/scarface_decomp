// bin: proto
// va: 0x0019F030
// what: 
// tool: the portal's starter code (no AI)

// sub_0019F030 (Proto 0x0019F030, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0019FD60(int);

int __cdecl sub_0019F030(int a1)
{
    int t1;

    t1 = sub_0019FD60(a1);
    if (t1) {
        return *(int*)(t1 + 16);
    }
    return 0;
}
