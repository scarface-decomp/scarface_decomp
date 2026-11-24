// bin: xb
// va: 0x003201C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003201C0 (0x003201C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E860[];
extern "C" Object DAT_0049275C;
extern "C" char sub_00231130[];

void __cdecl sub_003201C0(void)
{
    DAT_0049275C.sub_0006F830(0, (int)DAT_0044E860, (int)sub_00231130, 0, 2, 2);
}
