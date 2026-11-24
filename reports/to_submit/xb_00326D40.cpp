// bin: xb
// va: 0x00326D40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326D40 (0x00326D40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043DA48;
extern "C" int DAT_0043DA4C;
extern "C" unsigned short DAT_0043DA54;
extern "C" unsigned short DAT_0043DA56;
extern "C" unsigned short DAT_0043DA5A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326D40(void)
{
    DAT_0043DA48 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043DA4C);
    DAT_0043DA4C = 0;
    DAT_0043DA54 = 0;
    DAT_0043DA56 = 0;
    DAT_0043DA5A = 0;
    return 0;
}
