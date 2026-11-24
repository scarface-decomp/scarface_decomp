// bin: xb
// va: 0x00324050
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324050 (0x00324050, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00429688;
extern "C" int DAT_0042968C;
extern "C" unsigned short DAT_00429694;
extern "C" unsigned short DAT_00429696;
extern "C" unsigned short DAT_0042969A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324050(void)
{
    DAT_00429688 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042968C);
    DAT_0042968C = 0;
    DAT_00429694 = 0;
    DAT_00429696 = 0;
    DAT_0042969A = 0;
    return 0;
}
