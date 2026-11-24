// bin: xb
// va: 0x003282A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003282A0 (0x003282A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004477F4;
extern "C" int DAT_004477F8;
extern "C" unsigned short DAT_00447800;
extern "C" unsigned short DAT_00447802;
extern "C" unsigned short DAT_00447806;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003282A0(void)
{
    DAT_004477F4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004477F8);
    DAT_004477F8 = 0;
    DAT_00447800 = 0;
    DAT_00447802 = 0;
    DAT_00447806 = 0;
    return 0;
}
