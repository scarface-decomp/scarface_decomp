// bin: xb
// va: 0x00325610
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325610 (0x00325610, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004367D4;
extern "C" int DAT_004367D8;
extern "C" unsigned short DAT_004367E0;
extern "C" unsigned short DAT_004367E2;
extern "C" unsigned short DAT_004367E6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325610(void)
{
    DAT_004367D4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004367D8);
    DAT_004367D8 = 0;
    DAT_004367E0 = 0;
    DAT_004367E2 = 0;
    DAT_004367E6 = 0;
    return 0;
}
