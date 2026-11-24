// bin: xb
// va: 0x00323040
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323040 (0x00323040, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00423654;
extern "C" int DAT_00423658;
extern "C" unsigned short DAT_00423660;
extern "C" unsigned short DAT_00423662;
extern "C" unsigned short DAT_00423666;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323040(void)
{
    DAT_00423654 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00423658);
    DAT_00423658 = 0;
    DAT_00423660 = 0;
    DAT_00423662 = 0;
    DAT_00423666 = 0;
    return 0;
}
