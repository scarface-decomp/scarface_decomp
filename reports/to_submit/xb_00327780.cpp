// bin: xb
// va: 0x00327780
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327780 (0x00327780, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004404BC;
extern "C" int DAT_004404C0;
extern "C" unsigned short DAT_004404C8;
extern "C" unsigned short DAT_004404CA;
extern "C" unsigned short DAT_004404CE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327780(void)
{
    DAT_004404BC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004404C0);
    DAT_004404C0 = 0;
    DAT_004404C8 = 0;
    DAT_004404CA = 0;
    DAT_004404CE = 0;
    return 0;
}
