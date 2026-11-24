// bin: proto
// va: 0x002E0300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0300 (Proto 0x002E0300, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4E80[];
extern "C" char DAT_003F4E88[];
extern "C" Object DAT_00446930;
extern "C" char sub_0001E830[];

void __cdecl sub_002E0300(void)
{
    DAT_00446930.sub_00065550((int)DAT_003F4E88, (int)DAT_003F4E80, (int)sub_0001E830, 0, 2, 2);
}
