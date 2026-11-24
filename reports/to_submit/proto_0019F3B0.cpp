// bin: proto
// va: 0x0019F3B0
// what: 
// tool: the portal's starter code (no AI)

// sub_0019F3B0 (Proto 0x0019F3B0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A0320(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0019F3B0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001A0320(sub_002C96FE(*(int*)(a3 + 8)));
}
