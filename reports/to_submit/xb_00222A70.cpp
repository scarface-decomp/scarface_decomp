// bin: xb
// va: 0x00222A70
// what: 
// tool: the portal's starter code (no AI)

// sub_00222A70 (0x00222A70, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0021F6E0(int);
extern "C" void __cdecl sub_00220D90(int);

void __cdecl sub_00222A70(int a1, int a2, int a3)
{
    sub_00220D90(sub_0021F6E0(*(int*)(a3 + 4)));
}
