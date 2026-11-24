// bin: xb
// va: 0x00318640
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318640 (0x00318640, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FDD8[];
extern "C" char DAT_0042FDFC[];
extern "C" Object DAT_0048B368;
extern "C" char sub_00178270[];

void __cdecl sub_00318640(void)
{
    DAT_0048B368.sub_0006F880((int)DAT_0042FDFC, (int)DAT_0042FDD8, (int)sub_00178270, 0, 2, 2);
}
