// bin: xb
// va: 0x00222DE0
// what: 
// tool: the portal's starter code (no AI)

// sub_00222DE0 (0x00222DE0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00099BC0(int);
extern "C" void __cdecl sub_0021FC80(int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_00222DE0(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_00099BC0(*(int*)(a3 + 8));
    sub_0021FC80(sub_002FC43E(*(int*)(a3 + 4)), t2);
}
