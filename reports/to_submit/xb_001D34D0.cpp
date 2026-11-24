// bin: xb
// va: 0x001D34D0
// what: 
// tool: the portal's starter code (no AI)

// sub_001D34D0 (0x001D34D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D3970(int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001D34D0(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_002FC43E(*(int*)(a3 + 4));
    sub_001D3970(t2, sub_002FC43E(*(int*)(a3 + 8)));
}
