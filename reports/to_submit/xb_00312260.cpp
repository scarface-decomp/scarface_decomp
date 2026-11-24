// bin: xb
// va: 0x00312260
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312260 (0x00312260, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00419FD4[];
extern "C" char DAT_00419FE0[];
extern "C" Object DAT_00471658;
extern "C" char sub_00020A00[];

void __cdecl sub_00312260(void)
{
    DAT_00471658.sub_0006F880((int)DAT_00419FE0, (int)DAT_00419FD4, (int)sub_00020A00, 0, 2, 2);
}
