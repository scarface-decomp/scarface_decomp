// bin: xb
// va: 0x001D7570
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7570 (0x001D7570, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_00099BC0(int);

void __cdecl sub_001D7570(int a1, int a2, int a3)
{
    *(unsigned char*)(a1 + 61) = sub_00099BC0(*(int*)(a3 + 8));
}
