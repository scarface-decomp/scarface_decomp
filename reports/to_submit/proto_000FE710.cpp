// bin: proto
// va: 0x000FE710
// what: 
// tool: the portal's starter code (no AI)

// sub_000FE710 (Proto 0x000FE710, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EDAF0(int);
};

void __cdecl sub_000FE710(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_000EDAF0(*(int*)(a3 + 8));
}
