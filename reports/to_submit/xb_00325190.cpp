// bin: xb
// va: 0x00325190
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325190 (0x00325190, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00435E84;
extern "C" int DAT_00435E88;
extern "C" unsigned short DAT_00435E90;
extern "C" unsigned short DAT_00435E92;
extern "C" unsigned short DAT_00435E96;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325190(void)
{
    DAT_00435E84 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00435E88);
    DAT_00435E88 = 0;
    DAT_00435E90 = 0;
    DAT_00435E92 = 0;
    DAT_00435E96 = 0;
    return 0;
}
