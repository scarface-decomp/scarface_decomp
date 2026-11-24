// bin: xb
// va: 0x003281A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003281A0 (0x003281A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447744;
extern "C" int DAT_00447748;
extern "C" unsigned short DAT_00447750;
extern "C" unsigned short DAT_00447752;
extern "C" unsigned short DAT_00447756;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003281A0(void)
{
    DAT_00447744 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00447748);
    DAT_00447748 = 0;
    DAT_00447750 = 0;
    DAT_00447752 = 0;
    DAT_00447756 = 0;
    return 0;
}
