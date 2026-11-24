// bin: xb
// va: 0x00326B00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326B00 (0x00326B00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D8BC;
extern "C" int DAT_0043D8C0;
extern "C" unsigned short DAT_0043D8C8;
extern "C" unsigned short DAT_0043D8CA;
extern "C" unsigned short DAT_0043D8CE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326B00(void)
{
    DAT_0043D8BC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D8C0);
    DAT_0043D8C0 = 0;
    DAT_0043D8C8 = 0;
    DAT_0043D8CA = 0;
    DAT_0043D8CE = 0;
    return 0;
}
