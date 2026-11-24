// bin: xb
// va: 0x00312700
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312700 (0x00312700, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041AB00[];
extern "C" char DAT_0041AB10[];
extern "C" Object DAT_00471A5C;
extern "C" char sub_00024E20[];

void __cdecl sub_00312700(void)
{
    DAT_00471A5C.sub_0006F830((int)DAT_0041AB10, (int)DAT_0041AB00, (int)sub_00024E20, 0, 2, 2);
}
