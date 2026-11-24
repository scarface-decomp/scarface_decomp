// bin: xb
// va: 0x00328460
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328460 (0x00328460, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447928;
extern "C" int DAT_0044792C;
extern "C" unsigned short DAT_00447934;
extern "C" unsigned short DAT_00447936;
extern "C" unsigned short DAT_0044793A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328460(void)
{
    DAT_00447928 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044792C);
    DAT_0044792C = 0;
    DAT_00447934 = 0;
    DAT_00447936 = 0;
    DAT_0044793A = 0;
    return 0;
}
