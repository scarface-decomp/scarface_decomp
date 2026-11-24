// bin: xb
// va: 0x00319940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319940 (0x00319940, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436080[];
extern "C" char DAT_00436088[];
extern "C" Object DAT_0048D29C;
extern "C" char sub_001BCA30[];

void __cdecl sub_00319940(void)
{
    DAT_0048D29C.sub_0006F830((int)DAT_00436088, (int)DAT_00436080, (int)sub_001BCA30, 0, 3, 3);
}
