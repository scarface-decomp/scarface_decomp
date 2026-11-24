// bin: xb
// va: 0x0031FE40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FE40 (0x0031FE40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E378[];
extern "C" Object DAT_0049228C;
extern "C" char sub_002305E0[];

void __cdecl sub_0031FE40(void)
{
    DAT_0049228C.sub_0006F830(0, (int)DAT_0044E378, (int)sub_002305E0, 0, 2, 2);
}
