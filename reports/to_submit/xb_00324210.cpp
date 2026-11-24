// bin: xb
// va: 0x00324210
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324210 (0x00324210, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004297BC;
extern "C" int DAT_004297C0;
extern "C" unsigned short DAT_004297C8;
extern "C" unsigned short DAT_004297CA;
extern "C" unsigned short DAT_004297CE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324210(void)
{
    DAT_004297BC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004297C0);
    DAT_004297C0 = 0;
    DAT_004297C8 = 0;
    DAT_004297CA = 0;
    DAT_004297CE = 0;
    return 0;
}
