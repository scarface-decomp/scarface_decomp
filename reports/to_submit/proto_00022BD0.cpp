// bin: proto
// va: 0x00022BD0
// what: 
// tool: the portal's starter code (no AI)

// sub_00022BD0 (Proto 0x00022BD0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000226C0(int, int, int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00022BD0(int a1, int a2, int a3)
{
    sub_000226C0(*(int*)(a3 + 4), *(int*)(a3 + 8), *(int*)(a3 + 12), sub_002C96FE(*(int*)(a3 + 16)));
}
