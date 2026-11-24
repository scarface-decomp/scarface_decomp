// bin: proto
// va: 0x001E59A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001E59A0 (Proto 0x001E59A0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0008E600(int);
extern "C" void __cdecl sub_001E4800(int);

void __cdecl sub_001E59A0(int a1, int a2, int a3)
{
    sub_001E4800(sub_0008E600(*(int*)(a3 + 4)));
}
