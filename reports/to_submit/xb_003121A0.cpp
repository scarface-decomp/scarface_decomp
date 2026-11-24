// bin: xb
// va: 0x003121A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003121A0 (0x003121A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419F40[];
extern "C" char DAT_00419F50[];
extern "C" Object DAT_00471550;
extern "C" char sub_000208B0[];

void __cdecl sub_003121A0(void)
{
    DAT_00471550.sub_0006F830((int)DAT_00419F50, (int)DAT_00419F40, (int)sub_000208B0, 0, 5, 6);
}
