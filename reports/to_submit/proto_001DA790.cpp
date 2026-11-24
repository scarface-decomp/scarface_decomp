// bin: proto
// va: 0x001DA790
// what: 
// tool: the portal's starter code (no AI)

// sub_001DA790 (Proto 0x001DA790, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000279D0(int);
};

void __cdecl sub_001DA790(int a1)
{
    ((Object*)a1)->sub_000279D0(0x453B8000);
    *(unsigned char*)(a1 + 220) |= 2;
}
