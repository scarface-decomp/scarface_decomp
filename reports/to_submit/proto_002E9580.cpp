// bin: proto
// va: 0x002E9580
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9580 (Proto 0x002E9580, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041588C[];
extern "C" Object DAT_00460B50;
extern "C" char sub_001AC2C0[];

void __cdecl sub_002E9580(void)
{
    DAT_00460B50.sub_00065550(0, (int)DAT_0041588C, (int)sub_001AC2C0, 0, 6, 8);
}
