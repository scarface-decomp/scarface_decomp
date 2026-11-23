// bin: xb
// va: 0x001BC970
// what: 
// tool: the portal's starter code (no AI)

// sub_001BC970 (0x001BC970, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0018D500(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BC970(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_0018D500(sub_002FC43E(*(int*)(a3 + 8)));
}
