// bin: xb
// va: 0x00326C80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326C80 (0x00326C80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043D9C4;
extern "C" int DAT_0043D9C8;
extern "C" unsigned short DAT_0043D9D0;
extern "C" unsigned short DAT_0043D9D2;
extern "C" unsigned short DAT_0043D9D6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326C80(void)
{
    DAT_0043D9C4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043D9C8);
    DAT_0043D9C8 = 0;
    DAT_0043D9D0 = 0;
    DAT_0043D9D2 = 0;
    DAT_0043D9D6 = 0;
    return 0;
}
