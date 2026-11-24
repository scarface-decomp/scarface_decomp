// bin: xb
// va: 0x003237D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003237D0 (0x003237D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004290B0;
extern "C" int DAT_004290B4;
extern "C" unsigned short DAT_004290BC;
extern "C" unsigned short DAT_004290BE;
extern "C" unsigned short DAT_004290C2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003237D0(void)
{
    DAT_004290B0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004290B4);
    DAT_004290B4 = 0;
    DAT_004290BC = 0;
    DAT_004290BE = 0;
    DAT_004290C2 = 0;
    return 0;
}
