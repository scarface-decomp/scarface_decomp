// bin: proto
// va: 0x0018BDF0
// what: 
// tool: the portal's starter code (no AI)

// sub_0018BDF0 (Proto 0x0018BDF0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0016ED30(int);
    void sub_001814F0(int);
    void sub_00181520(int);
};

extern "C" int DAT_0045E07C;
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0018BDF0(int a1, int a2, int a3)
{
    int t1;

    t1 = ((Object*)DAT_0045E07C)->sub_0016ED30(66);
    if (t1) {
        *(int*)(t1 + 88) = sub_002C96FE(*(int*)(a3 + 4));
        *(int*)(t1 + 92) = sub_002C96FE(*(int*)(a3 + 8));
        *(int*)(t1 + 96) = sub_002C96FE(*(int*)(a3 + 12));
        ((Object*)t1)->sub_001814F0(*(int*)(a3 + 16));
        ((Object*)t1)->sub_00181520(*(int*)(a3 + 20));
    }
}
