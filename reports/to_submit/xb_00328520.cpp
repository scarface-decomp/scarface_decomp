// bin: xb
// va: 0x00328520
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328520 (0x00328520, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004479AC;
extern "C" int DAT_004479B0;
extern "C" unsigned short DAT_004479B8;
extern "C" unsigned short DAT_004479BA;
extern "C" unsigned short DAT_004479BE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328520(void)
{
    DAT_004479AC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004479B0);
    DAT_004479B0 = 0;
    DAT_004479B8 = 0;
    DAT_004479BA = 0;
    DAT_004479BE = 0;
    return 0;
}
