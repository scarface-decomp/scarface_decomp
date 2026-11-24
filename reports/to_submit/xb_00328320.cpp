// bin: xb
// va: 0x00328320
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328320 (0x00328320, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044784C;
extern "C" int DAT_00447850;
extern "C" unsigned short DAT_00447858;
extern "C" unsigned short DAT_0044785A;
extern "C" unsigned short DAT_0044785E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328320(void)
{
    DAT_0044784C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447850);
    DAT_00447850 = 0;
    DAT_00447858 = 0;
    DAT_0044785A = 0;
    DAT_0044785E = 0;
    return 0;
}
