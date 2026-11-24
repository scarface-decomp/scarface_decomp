// bin: xb
// va: 0x003243C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003243C0 (0x003243C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042D7B8;
extern "C" int DAT_0042D7BC;
extern "C" unsigned short DAT_0042D7C4;
extern "C" unsigned short DAT_0042D7C6;
extern "C" unsigned short DAT_0042D7CA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003243C0(void)
{
    DAT_0042D7B8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042D7BC);
    DAT_0042D7BC = 0;
    DAT_0042D7C4 = 0;
    DAT_0042D7C6 = 0;
    DAT_0042D7CA = 0;
    return 0;
}
