// bin: proto
// va: 0x002E8DD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8DD0 (Proto 0x002E8DD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00413D5C[];
extern "C" char DAT_00413D64[];
extern "C" Object DAT_00460360;
extern "C" char sub_0019ADE0[];

void __cdecl sub_002E8DD0(void)
{
    DAT_00460360.sub_000654B0((int)DAT_00413D64, (int)DAT_00413D5C, (int)sub_0019ADE0, 0, 2, 2);
}
