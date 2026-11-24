// bin: xb
// va: 0x00325790
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325790 (0x00325790, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436B30;
extern "C" int DAT_00436B34;
extern "C" unsigned short DAT_00436B3C;
extern "C" unsigned short DAT_00436B3E;
extern "C" unsigned short DAT_00436B42;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325790(void)
{
    DAT_00436B30 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436B34);
    DAT_00436B34 = 0;
    DAT_00436B3C = 0;
    DAT_00436B3E = 0;
    DAT_00436B42 = 0;
    return 0;
}
