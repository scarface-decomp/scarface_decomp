// bin: xb
// va: 0x00326250
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326250 (0x00326250, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439DA4;
extern "C" int DAT_00439DA8;
extern "C" unsigned short DAT_00439DB0;
extern "C" unsigned short DAT_00439DB2;
extern "C" unsigned short DAT_00439DB6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326250(void)
{
    DAT_00439DA4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439DA8);
    DAT_00439DA8 = 0;
    DAT_00439DB0 = 0;
    DAT_00439DB2 = 0;
    DAT_00439DB6 = 0;
    return 0;
}
