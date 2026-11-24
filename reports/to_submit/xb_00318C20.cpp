// bin: xb
// va: 0x00318C20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318C20 (0x00318C20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430474[];
extern "C" char DAT_0043048C[];
extern "C" Object DAT_0048BB7C;
extern "C" char sub_001790E0[];

void __cdecl sub_00318C20(void)
{
    DAT_0048BB7C.sub_0006F830((int)DAT_0043048C, (int)DAT_00430474, (int)sub_001790E0, 0, 4, 4);
}
