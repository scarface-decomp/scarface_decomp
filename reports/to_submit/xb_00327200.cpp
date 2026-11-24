// bin: xb
// va: 0x00327200
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327200 (0x00327200, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E76C;
extern "C" int DAT_0043E770;
extern "C" unsigned short DAT_0043E778;
extern "C" unsigned short DAT_0043E77A;
extern "C" unsigned short DAT_0043E77E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327200(void)
{
    DAT_0043E76C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E770);
    DAT_0043E770 = 0;
    DAT_0043E778 = 0;
    DAT_0043E77A = 0;
    DAT_0043E77E = 0;
    return 0;
}
