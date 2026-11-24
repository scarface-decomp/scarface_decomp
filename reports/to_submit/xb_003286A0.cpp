// bin: xb
// va: 0x003286A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003286A0 (0x003286A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447B0C;
extern "C" int DAT_00447B10;
extern "C" unsigned short DAT_00447B18;
extern "C" unsigned short DAT_00447B1A;
extern "C" unsigned short DAT_00447B1E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003286A0(void)
{
    DAT_00447B0C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447B10);
    DAT_00447B10 = 0;
    DAT_00447B18 = 0;
    DAT_00447B1A = 0;
    DAT_00447B1E = 0;
    return 0;
}
