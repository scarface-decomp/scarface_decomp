// bin: xb
// va: 0x003132B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003132B0 (0x003132B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A0538[];
extern "C" Object DAT_00475788;
extern "C" char sub_0004C120[];

void __cdecl sub_003132B0(void)
{
    DAT_00475788.sub_000EB3A0(12, 1, 1, 54, 42, (int)DAT_003A0538, (int)sub_0004C120, 509, 3, 1);
}
