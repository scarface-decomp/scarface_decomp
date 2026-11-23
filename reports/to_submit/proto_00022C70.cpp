// bin: proto
// va: 0x00022C70
// what: 
// tool: the portal's starter code (no AI)

// sub_00022C70 (Proto 0x00022C70, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0020AFF0(int, int);

void __cdecl sub_00022C70(int a1, int a2, int a3)
{
    sub_0020AFF0(*(int*)(a3 + 4), *(int*)(a3 + 8));
}
