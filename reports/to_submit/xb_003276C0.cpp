// bin: xb
// va: 0x003276C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003276C0 (0x003276C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00440258;
extern "C" int DAT_0044025C;
extern "C" unsigned short DAT_00440264;
extern "C" unsigned short DAT_00440266;
extern "C" unsigned short DAT_0044026A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003276C0(void)
{
    DAT_00440258 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044025C);
    DAT_0044025C = 0;
    DAT_00440264 = 0;
    DAT_00440266 = 0;
    DAT_0044026A = 0;
    return 0;
}
