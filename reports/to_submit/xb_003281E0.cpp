// bin: xb
// va: 0x003281E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003281E0 (0x003281E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447770;
extern "C" int DAT_00447774;
extern "C" unsigned short DAT_0044777C;
extern "C" unsigned short DAT_0044777E;
extern "C" unsigned short DAT_00447782;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003281E0(void)
{
    DAT_00447770 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447774);
    DAT_00447774 = 0;
    DAT_0044777C = 0;
    DAT_0044777E = 0;
    DAT_00447782 = 0;
    return 0;
}
