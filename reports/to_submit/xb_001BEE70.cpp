// bin: xb
// va: 0x001BEE70
// what: 
// tool: the portal's starter code (no AI)

// sub_001BEE70 (0x001BEE70, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001AB850(int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BEE70(int a1, int a2, int a3)
{
    sub_001AB850(sub_002FC43E(*(int*)(a3 + 4)));
}
