// bin: proto
// va: 0x00055E80
// what: 
// tool: the portal's starter code (no AI)

// sub_00055E80 (Proto 0x00055E80, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0005A100(int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00055E80(int a1, int a2, int a3)
{
    sub_0005A100(sub_002C96FE(*(int*)(a3 + 4)));
}
