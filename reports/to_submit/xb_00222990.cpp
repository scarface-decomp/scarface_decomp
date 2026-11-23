// bin: xb
// va: 0x00222990
// what: 
// tool: the portal's starter code (no AI)

// sub_00222990 (0x00222990, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0021F6E0(int);

int __cdecl sub_00222990(int a1, int a2, int a3)
{
    return sub_0021F6E0(*(int*)(a3 + 4));
}
