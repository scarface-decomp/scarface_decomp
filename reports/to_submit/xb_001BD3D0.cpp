// bin: xb
// va: 0x001BD3D0
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD3D0 (0x001BD3D0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B30A0(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BD3D0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001B30A0(sub_002FC43E(*(int*)(a3 + 8)));
}
