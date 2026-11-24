// bin: xb
// va: 0x00328C20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328C20 (0x00328C20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044BA28;
extern "C" int DAT_0044BA2C;
extern "C" unsigned short DAT_0044BA34;
extern "C" unsigned short DAT_0044BA36;
extern "C" unsigned short DAT_0044BA3A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328C20(void)
{
    DAT_0044BA28 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044BA2C);
    DAT_0044BA2C = 0;
    DAT_0044BA34 = 0;
    DAT_0044BA36 = 0;
    DAT_0044BA3A = 0;
    return 0;
}
