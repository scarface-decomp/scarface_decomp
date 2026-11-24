// bin: xb
// va: 0x00326110
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326110 (0x00326110, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043949C;
extern "C" int DAT_004394A0;
extern "C" unsigned short DAT_004394A8;
extern "C" unsigned short DAT_004394AA;
extern "C" unsigned short DAT_004394AE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326110(void)
{
    DAT_0043949C = (int)DAT_0039D4E4;
    sub_00027600(DAT_004394A0);
    DAT_004394A0 = 0;
    DAT_004394A8 = 0;
    DAT_004394AA = 0;
    DAT_004394AE = 0;
    return 0;
}
