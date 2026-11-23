// bin: proto
// va: 0x0006C780
// what: 
// tool: the portal's starter code (no AI)

// sub_0006C780 (Proto 0x0006C780, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00072DD0(int, int);
extern "C" int __cdecl sub_0008E600(int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0006C780(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_0008E600(*(int*)(a3 + 8));
    sub_00072DD0(sub_002C96FE(*(int*)(a3 + 4)), t2);
}
