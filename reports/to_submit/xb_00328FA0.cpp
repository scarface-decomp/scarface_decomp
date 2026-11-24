// bin: xb
// va: 0x00328FA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328FA0 (0x00328FA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044CC34;
extern "C" int DAT_0044CC38;
extern "C" unsigned short DAT_0044CC40;
extern "C" unsigned short DAT_0044CC42;
extern "C" unsigned short DAT_0044CC46;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328FA0(void)
{
    DAT_0044CC34 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044CC38);
    DAT_0044CC38 = 0;
    DAT_0044CC40 = 0;
    DAT_0044CC42 = 0;
    DAT_0044CC46 = 0;
    return 0;
}
