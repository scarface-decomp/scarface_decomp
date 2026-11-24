// bin: proto
// va: 0x000392C0
// what: 
// tool: the portal's starter code (no AI)

// sub_000392C0 (Proto 0x000392C0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00040D10(int);
extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_000392C0(int a1, int a2, int a3)
{
    sub_00040D10(sub_0008E600(*(int*)(a3 + 4)));
}
