// bin: xb
// va: 0x00325810
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325810 (0x00325810, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436B88;
extern "C" int DAT_00436B8C;
extern "C" unsigned short DAT_00436B94;
extern "C" unsigned short DAT_00436B96;
extern "C" unsigned short DAT_00436B9A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325810(void)
{
    DAT_00436B88 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436B8C);
    DAT_00436B8C = 0;
    DAT_00436B94 = 0;
    DAT_00436B96 = 0;
    DAT_00436B9A = 0;
    return 0;
}
