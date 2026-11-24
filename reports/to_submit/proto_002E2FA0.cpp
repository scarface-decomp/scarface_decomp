// bin: proto
// va: 0x002E2FA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2FA0 (Proto 0x002E2FA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FDFFC[];
extern "C" Object DAT_00453E9C;
extern "C" char sub_00084C30[];

void __cdecl sub_002E2FA0(void)
{
    DAT_00453E9C.sub_00065550(0, (int)DAT_003FDFFC, (int)sub_00084C30, 0, 1, 1);
}
