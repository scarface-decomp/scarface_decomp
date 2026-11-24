// bin: xb
// va: 0x003236D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003236D0 (0x003236D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429000;
extern "C" int DAT_00429004;
extern "C" unsigned short DAT_0042900C;
extern "C" unsigned short DAT_0042900E;
extern "C" unsigned short DAT_00429012;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003236D0(void)
{
    DAT_00429000 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429004);
    DAT_00429004 = 0;
    DAT_0042900C = 0;
    DAT_0042900E = 0;
    DAT_00429012 = 0;
    return 0;
}
