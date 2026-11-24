// bin: xb
// va: 0x00328AA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328AA0 (0x00328AA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044ACB8;
extern "C" int DAT_0044ACBC;
extern "C" unsigned short DAT_0044ACC4;
extern "C" unsigned short DAT_0044ACC6;
extern "C" unsigned short DAT_0044ACCA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328AA0(void)
{
    DAT_0044ACB8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044ACBC);
    DAT_0044ACBC = 0;
    DAT_0044ACC4 = 0;
    DAT_0044ACC6 = 0;
    DAT_0044ACCA = 0;
    return 0;
}
