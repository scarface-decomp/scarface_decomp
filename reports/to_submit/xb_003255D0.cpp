// bin: xb
// va: 0x003255D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003255D0 (0x003255D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436774;
extern "C" int DAT_00436778;
extern "C" unsigned short DAT_00436780;
extern "C" unsigned short DAT_00436782;
extern "C" unsigned short DAT_00436786;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003255D0(void)
{
    DAT_00436774 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436778);
    DAT_00436778 = 0;
    DAT_00436780 = 0;
    DAT_00436782 = 0;
    DAT_00436786 = 0;
    return 0;
}
