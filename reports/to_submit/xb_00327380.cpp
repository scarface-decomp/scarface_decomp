// bin: xb
// va: 0x00327380
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327380 (0x00327380, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043EFD8;
extern "C" int DAT_0043EFDC;
extern "C" unsigned short DAT_0043EFE4;
extern "C" unsigned short DAT_0043EFE6;
extern "C" unsigned short DAT_0043EFEA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327380(void)
{
    DAT_0043EFD8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043EFDC);
    DAT_0043EFDC = 0;
    DAT_0043EFE4 = 0;
    DAT_0043EFE6 = 0;
    DAT_0043EFEA = 0;
    return 0;
}
