// bin: proto
// va: 0x002E8150
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8150 (Proto 0x002E8150, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411674[];
extern "C" char DAT_00411688[];
extern "C" Object DAT_0045FC90;
extern "C" char sub_0018BA80[];

void __cdecl sub_002E8150(void)
{
    DAT_0045FC90.sub_00065550((int)DAT_00411688, (int)DAT_00411674, (int)sub_0018BA80, 0, 2, 2);
}
