// bin: xb
// va: 0x00329020
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329020 (0x00329020, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044D438;
extern "C" int DAT_0044D43C;
extern "C" unsigned short DAT_0044D444;
extern "C" unsigned short DAT_0044D446;
extern "C" unsigned short DAT_0044D44A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00329020(void)
{
    DAT_0044D438 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044D43C);
    DAT_0044D43C = 0;
    DAT_0044D444 = 0;
    DAT_0044D446 = 0;
    DAT_0044D44A = 0;
    return 0;
}
