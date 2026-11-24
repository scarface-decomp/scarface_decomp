// bin: proto
// va: 0x0006C750
// what: 
// tool: the portal's starter code (no AI)

// sub_0006C750 (Proto 0x0006C750, 46 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001B7A10();
    void sub_00200310(int);
};

extern "C" int __cdecl sub_00073B00(int);

int __cdecl sub_0006C750(int a1, int a2, int a3)
{
    int t2;

    ((Object*)(int)(&a3))->sub_00200310(*(int*)(a3 + 4));
    t2 = sub_00073B00((int)(&a3));
    ((Object*)(int)(&a3))->sub_001B7A10();
    return t2;
}
