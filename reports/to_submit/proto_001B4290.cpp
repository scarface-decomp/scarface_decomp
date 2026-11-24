// bin: proto
// va: 0x001B4290
// what: 
// tool: the portal's starter code (no AI)

// sub_001B4290 (Proto 0x001B4290, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B5B30(int);
};

extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_001B4290(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001B5B30(sub_002014E0(*(int*)(a3 + 8), 0));
}
