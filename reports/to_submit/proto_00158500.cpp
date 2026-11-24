// bin: proto
// va: 0x00158500
// what: 
// tool: the portal's starter code (no AI)

// sub_00158500 (Proto 0x00158500, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00147EE0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_00158500(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_002C96FE(*(int*)(a3 + 8));
    if (t1 > 0) {
        ((Object*)a1)->sub_00147EE0(t1);
    }
}
