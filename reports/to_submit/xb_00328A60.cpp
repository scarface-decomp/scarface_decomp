// bin: xb
// va: 0x00328A60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328A60 (0x00328A60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044AC8C;
extern "C" int DAT_0044AC90;
extern "C" unsigned short DAT_0044AC98;
extern "C" unsigned short DAT_0044AC9A;
extern "C" unsigned short DAT_0044AC9E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328A60(void)
{
    DAT_0044AC8C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044AC90);
    DAT_0044AC90 = 0;
    DAT_0044AC98 = 0;
    DAT_0044AC9A = 0;
    DAT_0044AC9E = 0;
    return 0;
}
