// bin: proto
// va: 0x00022F40
// what: 
// tool: the portal's starter code (no AI)

// sub_00022F40 (Proto 0x00022F40, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000210F0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00022F40(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_000210F0(sub_002C96FE(*(int*)(a3 + 8)));
}
