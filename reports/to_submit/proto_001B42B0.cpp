// bin: proto
// va: 0x001B42B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001B42B0 (Proto 0x001B42B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B5BA0(int);
};

extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_001B42B0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001B5BA0(sub_002014E0(*(int*)(a3 + 8), 0));
}
