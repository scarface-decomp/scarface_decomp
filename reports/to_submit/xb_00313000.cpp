// bin: xb
// va: 0x00313000
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313000 (0x00313000, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A0190[];
extern "C" Object DAT_00474B2C;
extern "C" char sub_00038A60[];

void __cdecl sub_00313000(void)
{
    DAT_00474B2C.sub_000EB3A0(21, 23, 12, 61, 34, (int)DAT_003A0190, (int)sub_00038A60, 80, 0, 0);
}
