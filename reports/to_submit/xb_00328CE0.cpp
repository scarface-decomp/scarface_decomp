// bin: xb
// va: 0x00328CE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328CE0 (0x00328CE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044BD18;
extern "C" int DAT_0044BD1C;
extern "C" unsigned short DAT_0044BD24;
extern "C" unsigned short DAT_0044BD26;
extern "C" unsigned short DAT_0044BD2A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328CE0(void)
{
    DAT_0044BD18 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044BD1C);
    DAT_0044BD1C = 0;
    DAT_0044BD24 = 0;
    DAT_0044BD26 = 0;
    DAT_0044BD2A = 0;
    return 0;
}
