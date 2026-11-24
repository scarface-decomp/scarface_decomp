// bin: proto
// va: 0x0001E7B0
// what: 
// tool: the portal's starter code (no AI)

// sub_0001E7B0 (Proto 0x0001E7B0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0001D180(int, int, int, int, int, int, int, int);
};

void __cdecl sub_0001E7B0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_0001D180(*(int*)(a3 + 8), *(int*)(a3 + 12), 0, *(int*)(a3 + 16), 0, -1, 0, 0);
}
