// bin: proto
// va: 0x001F0F40
// what: 
// tool: the portal's starter code (no AI)

// sub_001F0F40 (Proto 0x001F0F40, 97 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00029A80(int, int, int);
    int sub_0008D4E0(int);
    void sub_000E2110(int);
    int sub_00148D30();
};

extern "C" char DAT_00381D90[];
extern "C" char DAT_003AC528[];
extern "C" char DAT_003AC550[];
extern "C" char DAT_003AC55C[];
extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;
extern "C" int __cdecl sub_00028120(int);

void __cdecl sub_001F0F40(int a1)
{
    int t2, t3;

    t2 = sub_00028120(*(int*)(a1 + 32));
    t3 = ((Object*)t2)->sub_00148D30();
    ((Object*)t3)->sub_000E2110(DAT_00462DD4.sub_0008D4E0(DAT_00462DD8));
    ((Object*)t2)->sub_00029A80((int)DAT_003AC550, 0, (int)DAT_003AC55C);
    ((Object*)a1)->sub_00029A80((int)DAT_003AC528, 0, (int)DAT_00381D90);
}
