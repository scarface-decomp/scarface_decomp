// bin: xb
// va: 0x003288E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003288E0 (0x003288E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447CA0;
extern "C" int DAT_00447CA4;
extern "C" unsigned short DAT_00447CAC;
extern "C" unsigned short DAT_00447CAE;
extern "C" unsigned short DAT_00447CB2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003288E0(void)
{
    DAT_00447CA0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447CA4);
    DAT_00447CA4 = 0;
    DAT_00447CAC = 0;
    DAT_00447CAE = 0;
    DAT_00447CB2 = 0;
    return 0;
}
