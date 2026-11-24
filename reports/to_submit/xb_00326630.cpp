// bin: xb
// va: 0x00326630
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326630 (0x00326630, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043ACA8;
extern "C" int DAT_0043ACAC;
extern "C" unsigned short DAT_0043ACB4;
extern "C" unsigned short DAT_0043ACB6;
extern "C" unsigned short DAT_0043ACBA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326630(void)
{
    DAT_0043ACA8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043ACAC);
    DAT_0043ACAC = 0;
    DAT_0043ACB4 = 0;
    DAT_0043ACB6 = 0;
    DAT_0043ACBA = 0;
    return 0;
}
