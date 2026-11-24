// bin: xb
// va: 0x00326390
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326390 (0x00326390, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439E80;
extern "C" int DAT_00439E84;
extern "C" unsigned short DAT_00439E8C;
extern "C" unsigned short DAT_00439E8E;
extern "C" unsigned short DAT_00439E92;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326390(void)
{
    DAT_00439E80 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439E84);
    DAT_00439E84 = 0;
    DAT_00439E8C = 0;
    DAT_00439E8E = 0;
    DAT_00439E92 = 0;
    return 0;
}
