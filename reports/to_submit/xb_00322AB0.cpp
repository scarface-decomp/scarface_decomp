// bin: xb
// va: 0x00322AB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322AB0 (0x00322AB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041B8B8;
extern "C" int DAT_0041B8BC;
extern "C" unsigned short DAT_0041B8C4;
extern "C" unsigned short DAT_0041B8C6;
extern "C" unsigned short DAT_0041B8CA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322AB0(void)
{
    DAT_0041B8B8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041B8BC);
    DAT_0041B8BC = 0;
    DAT_0041B8C4 = 0;
    DAT_0041B8C6 = 0;
    DAT_0041B8CA = 0;
    return 0;
}
