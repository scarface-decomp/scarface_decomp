// bin: xb
// va: 0x003168A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003168A0 (0x003168A0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AD2F8[];
extern "C" Object DAT_004897EC;
extern "C" char sub_00111D10[];

void __cdecl sub_003168A0(void)
{
    DAT_004897EC.sub_000EB3A0(43, 30, 27, 70, 11, (int)DAT_003AD2F8, (int)sub_00111D10, 64, 0, 0);
}
