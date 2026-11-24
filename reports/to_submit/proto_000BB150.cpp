// bin: proto
// va: 0x000BB150
// what: 
// tool: the portal's starter code (no AI)

// sub_000BB150 (Proto 0x000BB150, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0008E600(int);
extern "C" void __cdecl sub_000BB190(int);

void __cdecl sub_000BB150(int a1, int a2, int a3)
{
    sub_000BB190(sub_0008E600(*(int*)(a3 + 4)));
}
