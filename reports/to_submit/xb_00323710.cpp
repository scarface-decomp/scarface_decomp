// bin: xb
// va: 0x00323710
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323710 (0x00323710, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042902C;
extern "C" int DAT_00429030;
extern "C" unsigned short DAT_00429038;
extern "C" unsigned short DAT_0042903A;
extern "C" unsigned short DAT_0042903E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323710(void)
{
    DAT_0042902C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00429030);
    DAT_00429030 = 0;
    DAT_00429038 = 0;
    DAT_0042903A = 0;
    DAT_0042903E = 0;
    return 0;
}
