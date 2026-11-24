// bin: proto
// va: 0x002EA660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EA660 (Proto 0x002EA660, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041BDEC[];
extern "C" char DAT_0041BE00[];
extern "C" Object DAT_00461768;
extern "C" char sub_001C86B0[];

void __cdecl sub_002EA660(void)
{
    DAT_00461768.sub_00065550((int)DAT_0041BE00, (int)DAT_0041BDEC, (int)sub_001C86B0, 0, 3, 3);
}
