// bin: xb
// va: 0x00312970
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312970 (0x00312970, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B748[];
extern "C" char DAT_0041B750[];
extern "C" Object DAT_004741F8;
extern "C" char sub_0002D570[];

void __cdecl sub_00312970(void)
{
    DAT_004741F8.sub_0006F830((int)DAT_0041B750, (int)DAT_0041B748, (int)sub_0002D570, 0, 2, 2);
}
