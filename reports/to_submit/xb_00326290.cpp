// bin: xb
// va: 0x00326290
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326290 (0x00326290, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439DD0;
extern "C" int DAT_00439DD4;
extern "C" unsigned short DAT_00439DDC;
extern "C" unsigned short DAT_00439DDE;
extern "C" unsigned short DAT_00439DE2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326290(void)
{
    DAT_00439DD0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439DD4);
    DAT_00439DD4 = 0;
    DAT_00439DDC = 0;
    DAT_00439DDE = 0;
    DAT_00439DE2 = 0;
    return 0;
}
