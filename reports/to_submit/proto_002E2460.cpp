// bin: proto
// va: 0x002E2460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2460 (Proto 0x002E2460, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCF14[];
extern "C" Object DAT_0045324C;
extern "C" char sub_0006C5F0[];

void __cdecl sub_002E2460(void)
{
    DAT_0045324C.sub_00065550(0, (int)DAT_003FCF14, (int)sub_0006C5F0, 0, 2, 5);
}
