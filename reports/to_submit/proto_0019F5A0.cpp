// bin: proto
// va: 0x0019F5A0
// what: 
// tool: the portal's starter code (no AI)

// sub_0019F5A0 (Proto 0x0019F5A0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0008E600(int);

void __cdecl sub_0019F5A0(int a1, int a2, int a3)
{
    *(unsigned char*)(a1 + 61) = sub_0008E600(*(int*)(a3 + 8));
}
