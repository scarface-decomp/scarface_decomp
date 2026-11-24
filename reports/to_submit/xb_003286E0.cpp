// bin: xb
// va: 0x003286E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003286E0 (0x003286E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447B38;
extern "C" int DAT_00447B3C;
extern "C" unsigned short DAT_00447B44;
extern "C" unsigned short DAT_00447B46;
extern "C" unsigned short DAT_00447B4A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003286E0(void)
{
    DAT_00447B38 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447B3C);
    DAT_00447B3C = 0;
    DAT_00447B44 = 0;
    DAT_00447B46 = 0;
    DAT_00447B4A = 0;
    return 0;
}
