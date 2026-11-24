// bin: xb
// va: 0x00318980
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318980 (0x00318980, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00430174[];
extern "C" char DAT_0043018C[];
extern "C" Object DAT_0048B7E0;
extern "C" char sub_001785B0[];

void __cdecl sub_00318980(void)
{
    DAT_0048B7E0.sub_0006F880((int)DAT_0043018C, (int)DAT_00430174, (int)sub_001785B0, 0, 2, 3);
}
