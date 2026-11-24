// bin: proto
// va: 0x001DA9B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DA9B0 (Proto 0x001DA9B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001DB7B0(int);
    int sub_001DB8F0();
};

void __cdecl sub_001DA9B0(int a1, int a2, int a3)
{
    int t1;

    t1 = ((Object*)a1)->sub_001DB8F0();
    if (t1) {
        ((Object*)t1)->sub_001DB7B0(*(int*)(a3 + 8));
    }
}
