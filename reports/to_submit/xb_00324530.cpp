// bin: xb
// va: 0x00324530
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324530 (0x00324530, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042DF3C;
extern "C" int DAT_0042DF40;
extern "C" unsigned short DAT_0042DF48;
extern "C" unsigned short DAT_0042DF4A;
extern "C" unsigned short DAT_0042DF4E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324530(void)
{
    DAT_0042DF3C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042DF40);
    DAT_0042DF40 = 0;
    DAT_0042DF48 = 0;
    DAT_0042DF4A = 0;
    DAT_0042DF4E = 0;
    return 0;
}
