// bin: xb
// va: 0x00323000
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323000 (0x00323000, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00423628;
extern "C" int DAT_0042362C;
extern "C" unsigned short DAT_00423634;
extern "C" unsigned short DAT_00423636;
extern "C" unsigned short DAT_0042363A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323000(void)
{
    DAT_00423628 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042362C);
    DAT_0042362C = 0;
    DAT_00423634 = 0;
    DAT_00423636 = 0;
    DAT_0042363A = 0;
    return 0;
}
