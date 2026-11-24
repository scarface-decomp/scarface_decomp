// bin: xb
// va: 0x00324E60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324E60 (0x00324E60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00431410;
extern "C" int DAT_00431414;
extern "C" unsigned short DAT_0043141C;
extern "C" unsigned short DAT_0043141E;
extern "C" unsigned short DAT_00431422;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324E60(void)
{
    DAT_00431410 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00431414);
    DAT_00431414 = 0;
    DAT_0043141C = 0;
    DAT_0043141E = 0;
    DAT_00431422 = 0;
    return 0;
}
