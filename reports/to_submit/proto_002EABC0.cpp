// bin: proto
// va: 0x002EABC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EABC0 (Proto 0x002EABC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004213A4[];
extern "C" char DAT_004213B0[];
extern "C" Object DAT_004617A0;
extern "C" char sub_001CD600[];

void __cdecl sub_002EABC0(void)
{
    DAT_004617A0.sub_00065550((int)DAT_004213B0, (int)DAT_004213A4, (int)sub_001CD600, 0, 2, 2);
}
