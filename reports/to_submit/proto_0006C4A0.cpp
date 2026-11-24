// bin: proto
// va: 0x0006C4A0
// what: 
// tool: the portal's starter code (no AI)

// sub_0006C4A0 (Proto 0x0006C4A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0006D170(int, int);
extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_0006C4A0(int a1, int a2, int a3)
{
    sub_0006D170(*(int*)(a3 + 4), sub_0008E600(*(int*)(a3 + 8)));
}
