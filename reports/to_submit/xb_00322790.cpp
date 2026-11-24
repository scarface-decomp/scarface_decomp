// bin: xb
// va: 0x00322790
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322790 (0x00322790, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041AC14;
extern "C" int DAT_0041AC18;
extern "C" unsigned short DAT_0041AC20;
extern "C" unsigned short DAT_0041AC22;
extern "C" unsigned short DAT_0041AC26;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322790(void)
{
    DAT_0041AC14 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041AC18);
    DAT_0041AC18 = 0;
    DAT_0041AC20 = 0;
    DAT_0041AC22 = 0;
    DAT_0041AC26 = 0;
    return 0;
}
