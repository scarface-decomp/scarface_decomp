// bin: xb
// va: 0x00326FC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326FC0 (0x00326FC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DC00;
extern "C" int DAT_0043DC04;
extern "C" unsigned short DAT_0043DC0C;
extern "C" unsigned short DAT_0043DC0E;
extern "C" unsigned short DAT_0043DC12;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326FC0(void)
{
    DAT_0043DC00 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DC04);
    DAT_0043DC04 = 0;
    DAT_0043DC0C = 0;
    DAT_0043DC0E = 0;
    DAT_0043DC12 = 0;
    return 0;
}
