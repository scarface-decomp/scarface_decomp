// bin: xb
// va: 0x00328EA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328EA0 (0x00328EA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044C374;
extern "C" int DAT_0044C378;
extern "C" unsigned short DAT_0044C380;
extern "C" unsigned short DAT_0044C382;
extern "C" unsigned short DAT_0044C386;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328EA0(void)
{
    DAT_0044C374 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044C378);
    DAT_0044C378 = 0;
    DAT_0044C380 = 0;
    DAT_0044C382 = 0;
    DAT_0044C386 = 0;
    return 0;
}
