// bin: xb
// va: 0x003168D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003168D0 (0x003168D0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AD32C[];
extern "C" Object DAT_004897F4;
extern "C" char sub_00112E20[];

void __cdecl sub_003168D0(void)
{
    DAT_004897F4.sub_000EB3A0(46, 32, 20, 72, 13, (int)DAT_003AD32C, (int)sub_00112E20, 64, 0, 0);
}
