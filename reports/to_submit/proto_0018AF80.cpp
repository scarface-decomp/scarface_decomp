// bin: proto
// va: 0x0018AF80
// what: 
// tool: the portal's starter code (no AI)

// sub_0018AF80 (Proto 0x0018AF80, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00175860(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0018AF80(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_002C96FE(*(int*)(a3 + 4));
    sub_00175860(t2, sub_002C96FE(*(int*)(a3 + 8)));
}
