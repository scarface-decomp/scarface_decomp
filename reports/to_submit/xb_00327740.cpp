// bin: xb
// va: 0x00327740
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327740 (0x00327740, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044042C;
extern "C" int DAT_00440430;
extern "C" unsigned short DAT_00440438;
extern "C" unsigned short DAT_0044043A;
extern "C" unsigned short DAT_0044043E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327740(void)
{
    DAT_0044042C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00440430);
    DAT_00440430 = 0;
    DAT_00440438 = 0;
    DAT_0044043A = 0;
    DAT_0044043E = 0;
    return 0;
}
