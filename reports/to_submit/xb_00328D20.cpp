// bin: xb
// va: 0x00328D20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328D20 (0x00328D20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044BDE0;
extern "C" int DAT_0044BDE4;
extern "C" unsigned short DAT_0044BDEC;
extern "C" unsigned short DAT_0044BDEE;
extern "C" unsigned short DAT_0044BDF2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328D20(void)
{
    DAT_0044BDE0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044BDE4);
    DAT_0044BDE4 = 0;
    DAT_0044BDEC = 0;
    DAT_0044BDEE = 0;
    DAT_0044BDF2 = 0;
    return 0;
}
