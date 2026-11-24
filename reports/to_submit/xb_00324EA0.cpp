// bin: xb
// va: 0x00324EA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324EA0 (0x00324EA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043143C;
extern "C" int DAT_00431440;
extern "C" unsigned short DAT_00431448;
extern "C" unsigned short DAT_0043144A;
extern "C" unsigned short DAT_0043144E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00324EA0(void)
{
    DAT_0043143C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00431440);
    DAT_00431440 = 0;
    DAT_00431448 = 0;
    DAT_0043144A = 0;
    DAT_0043144E = 0;
    return 0;
}
