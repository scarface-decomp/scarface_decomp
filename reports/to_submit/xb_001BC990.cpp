// bin: xb
// va: 0x001BC990
// what: 
// tool: the portal's starter code (no AI)

// sub_001BC990 (0x001BC990, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0018D2D0(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BC990(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_0018D2D0(sub_002FC43E(*(int*)(a3 + 8)));
}
