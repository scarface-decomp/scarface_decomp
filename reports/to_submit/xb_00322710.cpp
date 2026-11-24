// bin: xb
// va: 0x00322710
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322710 (0x00322710, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041ABBC;
extern "C" int DAT_0041ABC0;
extern "C" unsigned short DAT_0041ABC8;
extern "C" unsigned short DAT_0041ABCA;
extern "C" unsigned short DAT_0041ABCE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322710(void)
{
    DAT_0041ABBC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041ABC0);
    DAT_0041ABC0 = 0;
    DAT_0041ABC8 = 0;
    DAT_0041ABCA = 0;
    DAT_0041ABCE = 0;
    return 0;
}
