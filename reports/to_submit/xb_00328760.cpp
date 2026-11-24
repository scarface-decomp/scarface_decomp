// bin: xb
// va: 0x00328760
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328760 (0x00328760, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447B98;
extern "C" int DAT_00447B9C;
extern "C" unsigned short DAT_00447BA4;
extern "C" unsigned short DAT_00447BA6;
extern "C" unsigned short DAT_00447BAA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328760(void)
{
    DAT_00447B98 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447B9C);
    DAT_00447B9C = 0;
    DAT_00447BA4 = 0;
    DAT_00447BA6 = 0;
    DAT_00447BAA = 0;
    return 0;
}
