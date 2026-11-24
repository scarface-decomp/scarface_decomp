// bin: xb
// va: 0x00319AA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319AA0 (0x00319AA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043633C[];
extern "C" char DAT_00436344[];
extern "C" Object DAT_0048D378;
extern "C" char sub_001BCD10[];

void __cdecl sub_00319AA0(void)
{
    DAT_0048D378.sub_0006F830((int)DAT_00436344, (int)DAT_0043633C, (int)sub_001BCD10, 0, 3, 3);
}
