// bin: xb
// va: 0x00328BA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328BA0 (0x00328BA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044B050;
extern "C" int DAT_0044B054;
extern "C" unsigned short DAT_0044B05C;
extern "C" unsigned short DAT_0044B05E;
extern "C" unsigned short DAT_0044B062;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328BA0(void)
{
    DAT_0044B050 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044B054);
    DAT_0044B054 = 0;
    DAT_0044B05C = 0;
    DAT_0044B05E = 0;
    DAT_0044B062 = 0;
    return 0;
}
