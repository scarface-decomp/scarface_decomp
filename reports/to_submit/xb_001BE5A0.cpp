// bin: xb
// va: 0x001BE5A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001BE5A0 (0x001BE5A0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001A1030(int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BE5A0(int a1, int a2, int a3)
{
    sub_001A1030(sub_002FC43E(*(int*)(a3 + 4)));
}
