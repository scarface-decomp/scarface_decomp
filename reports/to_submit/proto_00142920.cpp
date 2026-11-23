// bin: proto
// va: 0x00142920
// what: 
// tool: the portal's starter code (no AI)

// sub_00142920 (Proto 0x00142920, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00140ED0(int);
};

void __cdecl sub_00142920(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00140ED0(*(int*)(a3 + 8));
}
