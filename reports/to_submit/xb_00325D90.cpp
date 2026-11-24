// bin: xb
// va: 0x00325D90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325D90 (0x00325D90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00437CBC;
extern "C" int DAT_00437CC0;
extern "C" unsigned short DAT_00437CC8;
extern "C" unsigned short DAT_00437CCA;
extern "C" unsigned short DAT_00437CCE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325D90(void)
{
    DAT_00437CBC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00437CC0);
    DAT_00437CC0 = 0;
    DAT_00437CC8 = 0;
    DAT_00437CCA = 0;
    DAT_00437CCE = 0;
    return 0;
}
