// bin: xb
// va: 0x00324980
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324980 (0x00324980, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042F19C;
extern "C" int DAT_0042F1A0;
extern "C" unsigned short DAT_0042F1A8;
extern "C" unsigned short DAT_0042F1AA;
extern "C" unsigned short DAT_0042F1AE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324980(void)
{
    DAT_0042F19C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042F1A0);
    DAT_0042F1A0 = 0;
    DAT_0042F1A8 = 0;
    DAT_0042F1AA = 0;
    DAT_0042F1AE = 0;
    return 0;
}
