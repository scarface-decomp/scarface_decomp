// bin: proto
// va: 0x000DB6F0
// what: 
// tool: the portal's starter code (no AI)

// sub_000DB6F0 (Proto 0x000DB6F0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000D9D10(int, int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_000DB6F0(int a1, int a2, int a3)
{
    sub_000D9D10(12, sub_002C96FE(*(int*)(a3 + 4)), 14);
}
