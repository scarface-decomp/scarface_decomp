// bin: proto
// va: 0x00022C20
// what: 
// tool: the portal's starter code (no AI)

// sub_00022C20 (Proto 0x00022C20, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00024AB0(int);
    void sub_00024AD0();
};

extern "C" void __cdecl sub_0020B740(int, int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00022C20(int a1, int a2, int a3)
{
    int local_4, t3;

    ((Object*)(int)(&local_4))->sub_00024AB0(5);
    t3 = sub_002C96FE(*(int*)(a3 + 8));
    sub_0020B740(sub_002C96FE(*(int*)(a3 + 4)), t3);
    ((Object*)(int)(&local_4))->sub_00024AD0();
}
