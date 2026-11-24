// bin: proto
// va: 0x002EC030
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC030 (Proto 0x002EC030, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004272C8[];
extern "C" Object DAT_004628AC;
extern "C" char sub_001E5850[];

void __cdecl sub_002EC030(void)
{
    DAT_004628AC.sub_00065550(0, (int)DAT_004272C8, (int)sub_001E5850, 0, 2, 2);
}
