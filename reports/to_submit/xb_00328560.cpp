// bin: xb
// va: 0x00328560
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328560 (0x00328560, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004479D8;
extern "C" int DAT_004479DC;
extern "C" unsigned short DAT_004479E4;
extern "C" unsigned short DAT_004479E6;
extern "C" unsigned short DAT_004479EA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328560(void)
{
    DAT_004479D8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004479DC);
    DAT_004479DC = 0;
    DAT_004479E4 = 0;
    DAT_004479E6 = 0;
    DAT_004479EA = 0;
    return 0;
}
