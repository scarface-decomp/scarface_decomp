// bin: xb
// va: 0x003164C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003164C0 (0x003164C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A93B4[];
extern "C" Object DAT_00489010;
extern "C" char sub_000EB900[];

void __cdecl sub_003164C0(void)
{
    DAT_00489010.sub_000EB3A0(8, 45, 37, 93, 53, (int)DAT_003A93B4, (int)sub_000EB900, 509, 3, 1);
}
