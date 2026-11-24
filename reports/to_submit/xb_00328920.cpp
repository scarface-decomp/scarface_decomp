// bin: xb
// va: 0x00328920
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328920 (0x00328920, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447CCC;
extern "C" int DAT_00447CD0;
extern "C" unsigned short DAT_00447CD8;
extern "C" unsigned short DAT_00447CDA;
extern "C" unsigned short DAT_00447CDE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328920(void)
{
    DAT_00447CCC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447CD0);
    DAT_00447CD0 = 0;
    DAT_00447CD8 = 0;
    DAT_00447CDA = 0;
    DAT_00447CDE = 0;
    return 0;
}
