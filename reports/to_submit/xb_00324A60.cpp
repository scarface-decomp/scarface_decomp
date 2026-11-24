// bin: xb
// va: 0x00324A60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324A60 (0x00324A60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042F2B8;
extern "C" int DAT_0042F2BC;
extern "C" unsigned short DAT_0042F2C4;
extern "C" unsigned short DAT_0042F2C6;
extern "C" unsigned short DAT_0042F2CA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324A60(void)
{
    DAT_0042F2B8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042F2BC);
    DAT_0042F2BC = 0;
    DAT_0042F2C4 = 0;
    DAT_0042F2C6 = 0;
    DAT_0042F2CA = 0;
    return 0;
}
