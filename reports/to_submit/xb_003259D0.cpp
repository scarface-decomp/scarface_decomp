// bin: xb
// va: 0x003259D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003259D0 (0x003259D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004371C0;
extern "C" int DAT_004371C4;
extern "C" unsigned short DAT_004371CC;
extern "C" unsigned short DAT_004371CE;
extern "C" unsigned short DAT_004371D2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003259D0(void)
{
    DAT_004371C0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004371C4);
    DAT_004371C4 = 0;
    DAT_004371CC = 0;
    DAT_004371CE = 0;
    DAT_004371D2 = 0;
    return 0;
}
