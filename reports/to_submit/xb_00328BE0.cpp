// bin: xb
// va: 0x00328BE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328BE0 (0x00328BE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044B07C;
extern "C" int DAT_0044B080;
extern "C" unsigned short DAT_0044B088;
extern "C" unsigned short DAT_0044B08A;
extern "C" unsigned short DAT_0044B08E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328BE0(void)
{
    DAT_0044B07C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044B080);
    DAT_0044B080 = 0;
    DAT_0044B088 = 0;
    DAT_0044B08A = 0;
    DAT_0044B08E = 0;
    return 0;
}
