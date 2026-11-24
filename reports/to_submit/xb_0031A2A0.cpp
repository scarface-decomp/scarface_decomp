// bin: xb
// va: 0x0031A2A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A2A0 (0x0031A2A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00437044[];
extern "C" char DAT_00437058[];
extern "C" Object DAT_0048DA84;
extern "C" char sub_001BE510[];

void __cdecl sub_0031A2A0(void)
{
    DAT_0048DA84.sub_0006F880((int)DAT_00437058, (int)DAT_00437044, (int)sub_001BE510, 0, 2, 2);
}
