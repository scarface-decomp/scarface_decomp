// bin: proto
// va: 0x002E8790
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8790 (Proto 0x002E8790, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004133C4[];
extern "C" char DAT_004133CC[];
extern "C" Object DAT_00460148;
extern "C" char sub_00196AD0[];

void __cdecl sub_002E8790(void)
{
    DAT_00460148.sub_00065550((int)DAT_004133CC, (int)DAT_004133C4, (int)sub_00196AD0, 0, 3, 3);
}
