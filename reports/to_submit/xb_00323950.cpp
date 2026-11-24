// bin: xb
// va: 0x00323950
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323950 (0x00323950, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004291B8;
extern "C" int DAT_004291BC;
extern "C" unsigned short DAT_004291C4;
extern "C" unsigned short DAT_004291C6;
extern "C" unsigned short DAT_004291CA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323950(void)
{
    DAT_004291B8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004291BC);
    DAT_004291BC = 0;
    DAT_004291C4 = 0;
    DAT_004291C6 = 0;
    DAT_004291CA = 0;
    return 0;
}
