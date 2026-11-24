// bin: proto
// va: 0x00055FC0
// what: 
// tool: the portal's starter code (no AI)

// sub_00055FC0 (Proto 0x00055FC0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000599D0(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00055FC0(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_002C96FE(*(int*)a3);
    sub_000599D0(t2, sub_002C96FE(*(int*)(a3 + 4)));
}
