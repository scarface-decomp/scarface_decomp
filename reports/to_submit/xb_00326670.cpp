// bin: xb
// va: 0x00326670
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326670 (0x00326670, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043B078;
extern "C" int DAT_0043B07C;
extern "C" unsigned short DAT_0043B084;
extern "C" unsigned short DAT_0043B086;
extern "C" unsigned short DAT_0043B08A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326670(void)
{
    DAT_0043B078 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043B07C);
    DAT_0043B07C = 0;
    DAT_0043B084 = 0;
    DAT_0043B086 = 0;
    DAT_0043B08A = 0;
    return 0;
}
