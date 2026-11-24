// bin: xb
// va: 0x00327680
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327680 (0x00327680, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004401AC;
extern "C" int DAT_004401B0;
extern "C" unsigned short DAT_004401B8;
extern "C" unsigned short DAT_004401BA;
extern "C" unsigned short DAT_004401BE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327680(void)
{
    DAT_004401AC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004401B0);
    DAT_004401B0 = 0;
    DAT_004401B8 = 0;
    DAT_004401BA = 0;
    DAT_004401BE = 0;
    return 0;
}
