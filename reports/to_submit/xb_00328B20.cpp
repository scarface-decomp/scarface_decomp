// bin: xb
// va: 0x00328B20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328B20 (0x00328B20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044AFF8;
extern "C" int DAT_0044AFFC;
extern "C" unsigned short DAT_0044B004;
extern "C" unsigned short DAT_0044B006;
extern "C" unsigned short DAT_0044B00A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328B20(void)
{
    DAT_0044AFF8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044AFFC);
    DAT_0044AFFC = 0;
    DAT_0044B004 = 0;
    DAT_0044B006 = 0;
    DAT_0044B00A = 0;
    return 0;
}
