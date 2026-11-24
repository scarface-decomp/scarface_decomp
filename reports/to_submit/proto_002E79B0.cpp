// bin: proto
// va: 0x002E79B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E79B0 (Proto 0x002E79B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410C5C[];
extern "C" char DAT_00410C64[];
extern "C" Object DAT_0045F3F8;
extern "C" char sub_0018AF10[];

void __cdecl sub_002E79B0(void)
{
    DAT_0045F3F8.sub_00065550((int)DAT_00410C64, (int)DAT_00410C5C, (int)sub_0018AF10, 0, 2, 2);
}
