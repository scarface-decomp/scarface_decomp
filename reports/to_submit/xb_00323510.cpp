// bin: xb
// va: 0x00323510
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323510 (0x00323510, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00428ECC;
extern "C" int DAT_00428ED0;
extern "C" unsigned short DAT_00428ED8;
extern "C" unsigned short DAT_00428EDA;
extern "C" unsigned short DAT_00428EDE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323510(void)
{
    DAT_00428ECC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428ED0);
    DAT_00428ED0 = 0;
    DAT_00428ED8 = 0;
    DAT_00428EDA = 0;
    DAT_00428EDE = 0;
    return 0;
}
