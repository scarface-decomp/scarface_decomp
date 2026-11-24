// bin: xb
// va: 0x003233D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003233D0 (0x003233D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004286FC;
extern "C" int DAT_00428700;
extern "C" unsigned short DAT_00428708;
extern "C" unsigned short DAT_0042870A;
extern "C" unsigned short DAT_0042870E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003233D0(void)
{
    DAT_004286FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00428700);
    DAT_00428700 = 0;
    DAT_00428708 = 0;
    DAT_0042870A = 0;
    DAT_0042870E = 0;
    return 0;
}
