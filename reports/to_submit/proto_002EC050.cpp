// bin: proto
// va: 0x002EC050
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC050 (Proto 0x002EC050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004272E0[];
extern "C" Object DAT_004628D8;
extern "C" char sub_001E5860[];

void __cdecl sub_002EC050(void)
{
    DAT_004628D8.sub_00065550(0, (int)DAT_004272E0, (int)sub_001E5860, 0, 1, 1);
}
