// bin: proto
// va: 0x0019ECF0
// what: 
// tool: the portal's starter code (no AI)

// sub_0019ECF0 (Proto 0x0019ECF0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0008E600(int);
extern "C" void __cdecl sub_0019DA50(int);

void __cdecl sub_0019ECF0(int a1, int a2, int a3)
{
    sub_0019DA50(sub_0008E600(*(int*)(a3 + 4)));
}
