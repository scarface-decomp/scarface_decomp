// bin: xb
// va: 0x003194E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003194E0 (0x003194E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00434060[];
extern "C" Object DAT_0048C194;
extern "C" char sub_00189700[];

void __cdecl sub_003194E0(void)
{
    DAT_0048C194.sub_0006F830(0, (int)DAT_00434060, (int)sub_00189700, 0, 1, 2);
}
