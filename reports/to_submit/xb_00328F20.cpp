// bin: xb
// va: 0x00328F20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328F20 (0x00328F20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044C808;
extern "C" int DAT_0044C80C;
extern "C" unsigned short DAT_0044C814;
extern "C" unsigned short DAT_0044C816;
extern "C" unsigned short DAT_0044C81A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328F20(void)
{
    DAT_0044C808 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044C80C);
    DAT_0044C80C = 0;
    DAT_0044C814 = 0;
    DAT_0044C816 = 0;
    DAT_0044C81A = 0;
    return 0;
}
