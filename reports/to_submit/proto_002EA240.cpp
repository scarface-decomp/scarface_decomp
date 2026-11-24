// bin: proto
// va: 0x002EA240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EA240 (Proto 0x002EA240, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004194DC[];
extern "C" char DAT_004194F4[];
extern "C" Object DAT_0046165C;
extern "C" char sub_001C1EC0[];

void __cdecl sub_002EA240(void)
{
    DAT_0046165C.sub_00065550((int)DAT_004194F4, (int)DAT_004194DC, (int)sub_001C1EC0, 0, 4, 4);
}
