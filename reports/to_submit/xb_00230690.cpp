// bin: xb
// va: 0x00230690
// what: 
// tool: the portal's starter code (no AI)

// sub_00230690 (0x00230690, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00099BC0(int);
extern "C" void __cdecl sub_001EA960(int);

void __cdecl sub_00230690(int a1, int a2, int a3)
{
    sub_001EA960(sub_00099BC0(*(int*)(a3 + 4)));
}
