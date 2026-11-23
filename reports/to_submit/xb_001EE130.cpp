// bin: xb
// va: 0x001EE130
// what: 
// tool: the portal's starter code (no AI)

// sub_001EE130 (0x001EE130, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001EFC10(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001EE130(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001EFC10(sub_002FC43E(*(int*)(a3 + 8)));
}
