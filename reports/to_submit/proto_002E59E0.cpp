// bin: proto
// va: 0x002E59E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E59E0 (Proto 0x002E59E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00409E2C[];
extern "C" char DAT_00409E3C[];
extern "C" Object DAT_0045C7AC;
extern "C" char sub_00142560[];

void __cdecl sub_002E59E0(void)
{
    DAT_0045C7AC.sub_000654B0((int)DAT_00409E3C, (int)DAT_00409E2C, (int)sub_00142560, 0, 3, 3);
}
