// bin: xb
// va: 0x00327F20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327F20 (0x00327F20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004446EC;
extern "C" int DAT_004446F0;
extern "C" unsigned short DAT_004446F8;
extern "C" unsigned short DAT_004446FA;
extern "C" unsigned short DAT_004446FE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327F20(void)
{
    DAT_004446EC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004446F0);
    DAT_004446F0 = 0;
    DAT_004446F8 = 0;
    DAT_004446FA = 0;
    DAT_004446FE = 0;
    return 0;
}
