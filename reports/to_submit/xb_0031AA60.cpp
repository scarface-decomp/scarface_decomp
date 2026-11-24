// bin: xb
// va: 0x0031AA60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AA60 (0x0031AA60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437BA4[];
extern "C" char DAT_00437BAC[];
extern "C" Object DAT_0048E2C4;
extern "C" char sub_001BF610[];

void __cdecl sub_0031AA60(void)
{
    DAT_0048E2C4.sub_0006F830((int)DAT_00437BAC, (int)DAT_00437BA4, (int)sub_001BF610, 0, 2, 2);
}
