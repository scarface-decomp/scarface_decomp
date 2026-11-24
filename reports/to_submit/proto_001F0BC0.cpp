// bin: proto
// va: 0x001F0BC0
// what: 
// tool: the portal's starter code (no AI)

// sub_001F0BC0 (Proto 0x001F0BC0, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000DF020(int, int);
    void sub_000E2110(int);
    int sub_00148D30();
};

extern "C" int __cdecl sub_00028120(int);

void __cdecl sub_001F0BC0(int a1)
{
    int t2;

    t2 = ((Object*)sub_00028120(*(int*)(a1 + 32)))->sub_00148D30();
    ((Object*)t2)->sub_000DF020(1, 0);
    ((Object*)t2)->sub_000E2110(0);
}
