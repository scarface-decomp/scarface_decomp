// bin: proto
// va: 0x000BAD70
// what: 
// tool: the portal's starter code (no AI)

// sub_000BAD70 (Proto 0x000BAD70, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B98F0(int, int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_000BAD70(int a1, int a2, int a3)
{
    int t2;

    t2 = sub_002C96FE(*(int*)(a3 + 12));
    ((Object*)a1)->sub_000B98F0(sub_002C96FE(*(int*)(a3 + 8)), t2);
}
