// bin: proto
// va: 0x001978D0
// what: 
// tool: the portal's starter code (no AI)

// sub_001978D0 (Proto 0x001978D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00196F90(int);
};

extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_001978D0(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_00196F90(sub_00201440(*(int*)(a3 + 8), 0));
}
