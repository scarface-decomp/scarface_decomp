// bin: xb
// va: 0x003284E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003284E0 (0x003284E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447980;
extern "C" int DAT_00447984;
extern "C" unsigned short DAT_0044798C;
extern "C" unsigned short DAT_0044798E;
extern "C" unsigned short DAT_00447992;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003284E0(void)
{
    DAT_00447980 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447984);
    DAT_00447984 = 0;
    DAT_0044798C = 0;
    DAT_0044798E = 0;
    DAT_00447992 = 0;
    return 0;
}
