// bin: xb
// va: 0x00328220
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328220 (0x00328220, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044779C;
extern "C" int DAT_004477A0;
extern "C" unsigned short DAT_004477A8;
extern "C" unsigned short DAT_004477AA;
extern "C" unsigned short DAT_004477AE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328220(void)
{
    DAT_0044779C = (int)DAT_0039D4E4;
    sub_00027600(DAT_004477A0);
    DAT_004477A0 = 0;
    DAT_004477A8 = 0;
    DAT_004477AA = 0;
    DAT_004477AE = 0;
    return 0;
}
