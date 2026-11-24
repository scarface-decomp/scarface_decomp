// bin: xb
// va: 0x00324BA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324BA0 (0x00324BA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042F92C;
extern "C" int DAT_0042F930;
extern "C" unsigned short DAT_0042F938;
extern "C" unsigned short DAT_0042F93A;
extern "C" unsigned short DAT_0042F93E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324BA0(void)
{
    DAT_0042F92C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042F930);
    DAT_0042F930 = 0;
    DAT_0042F938 = 0;
    DAT_0042F93A = 0;
    DAT_0042F93E = 0;
    return 0;
}
