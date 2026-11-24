// bin: xb
// va: 0x00327340
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327340 (0x00327340, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043EFAC;
extern "C" int DAT_0043EFB0;
extern "C" unsigned short DAT_0043EFB8;
extern "C" unsigned short DAT_0043EFBA;
extern "C" unsigned short DAT_0043EFBE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327340(void)
{
    DAT_0043EFAC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043EFB0);
    DAT_0043EFB0 = 0;
    DAT_0043EFB8 = 0;
    DAT_0043EFBA = 0;
    DAT_0043EFBE = 0;
    return 0;
}
