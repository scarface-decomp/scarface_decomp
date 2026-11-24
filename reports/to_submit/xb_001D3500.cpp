// bin: xb
// va: 0x001D3500
// what: 
// tool: the portal's starter code (no AI)

// sub_001D3500 (0x001D3500, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001D3990(int, int, int);
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001D3500(int a1, int a2, int a3)
{
    int t2, t3;

    t2 = sub_002FC43E(*(int*)(a3 + 4));
    t3 = sub_002FC43E(*(int*)(a3 + 8));
    sub_001D3990(t2, t3, sub_002FC43E(*(int*)(a3 + 12)));
}
