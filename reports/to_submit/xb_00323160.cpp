// bin: xb
// va: 0x00323160
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00323160 (0x00323160, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00424834;
extern "C" int DAT_00424838;
extern "C" unsigned short DAT_00424840;
extern "C" unsigned short DAT_00424842;
extern "C" unsigned short DAT_00424846;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00323160(void)
{
    DAT_00424834 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00424838);
    DAT_00424838 = 0;
    DAT_00424840 = 0;
    DAT_00424842 = 0;
    DAT_00424846 = 0;
    return 0;
}
