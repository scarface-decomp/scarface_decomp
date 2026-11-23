// bin: proto
// va: 0x001B4340
// what: 
// tool: the portal's starter code (no AI)

// sub_001B4340 (Proto 0x001B4340, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B51E0(int);
};

void __cdecl sub_001B4340(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001B51E0(*(int*)(a3 + 8));
}
