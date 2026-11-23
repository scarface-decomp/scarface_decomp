// bin: proto
// va: 0x000BAC40
// what: 
// tool: the portal's starter code (no AI)

// sub_000BAC40 (Proto 0x000BAC40, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BA1A0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_000BAC40(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_000BA1A0(sub_002C96FE(*(int*)(a3 + 8)));
}
