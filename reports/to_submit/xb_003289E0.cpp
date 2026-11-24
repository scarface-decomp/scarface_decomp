// bin: xb
// va: 0x003289E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003289E0 (0x003289E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044AC34;
extern "C" int DAT_0044AC38;
extern "C" unsigned short DAT_0044AC40;
extern "C" unsigned short DAT_0044AC42;
extern "C" unsigned short DAT_0044AC46;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003289E0(void)
{
    DAT_0044AC34 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044AC38);
    DAT_0044AC38 = 0;
    DAT_0044AC40 = 0;
    DAT_0044AC42 = 0;
    DAT_0044AC46 = 0;
    return 0;
}
