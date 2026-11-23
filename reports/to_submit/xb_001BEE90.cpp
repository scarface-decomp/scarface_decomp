// bin: xb
// va: 0x001BEE90
// what: 
// tool: the portal's starter code (no AI)

// sub_001BEE90 (0x001BEE90, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_001AB8F0(int);

int __cdecl sub_001BEE90(int a1, int a2, int a3)
{
    return sub_001AB8F0(*(int*)(a3 + 4));
}
