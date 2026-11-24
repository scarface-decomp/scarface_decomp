// bin: xb
// va: 0x00323810
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323810 (0x00323810, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004290DC;
extern "C" int DAT_004290E0;
extern "C" unsigned short DAT_004290E8;
extern "C" unsigned short DAT_004290EA;
extern "C" unsigned short DAT_004290EE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323810(void)
{
    DAT_004290DC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004290E0);
    DAT_004290E0 = 0;
    DAT_004290E8 = 0;
    DAT_004290EA = 0;
    DAT_004290EE = 0;
    return 0;
}
