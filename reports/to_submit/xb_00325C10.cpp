// bin: xb
// va: 0x00325C10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325C10 (0x00325C10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004378BC;
extern "C" int DAT_004378C0;
extern "C" unsigned short DAT_004378C8;
extern "C" unsigned short DAT_004378CA;
extern "C" unsigned short DAT_004378CE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325C10(void)
{
    DAT_004378BC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004378C0);
    DAT_004378C0 = 0;
    DAT_004378C8 = 0;
    DAT_004378CA = 0;
    DAT_004378CE = 0;
    return 0;
}
