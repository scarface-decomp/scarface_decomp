// bin: xb
// va: 0x00324250
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324250 (0x00324250, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004297E8;
extern "C" int DAT_004297EC;
extern "C" unsigned short DAT_004297F4;
extern "C" unsigned short DAT_004297F6;
extern "C" unsigned short DAT_004297FA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324250(void)
{
    DAT_004297E8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004297EC);
    DAT_004297EC = 0;
    DAT_004297F4 = 0;
    DAT_004297F6 = 0;
    DAT_004297FA = 0;
    return 0;
}
