// bin: xb
// va: 0x00323990
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323990 (0x00323990, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004291E4;
extern "C" int DAT_004291E8;
extern "C" unsigned short DAT_004291F0;
extern "C" unsigned short DAT_004291F2;
extern "C" unsigned short DAT_004291F6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323990(void)
{
    DAT_004291E4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004291E8);
    DAT_004291E8 = 0;
    DAT_004291F0 = 0;
    DAT_004291F2 = 0;
    DAT_004291F6 = 0;
    return 0;
}
