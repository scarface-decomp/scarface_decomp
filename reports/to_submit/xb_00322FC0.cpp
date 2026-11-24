// bin: xb
// va: 0x00322FC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322FC0 (0x00322FC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004235FC;
extern "C" int DAT_00423600;
extern "C" unsigned short DAT_00423608;
extern "C" unsigned short DAT_0042360A;
extern "C" unsigned short DAT_0042360E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322FC0(void)
{
    DAT_004235FC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00423600);
    DAT_00423600 = 0;
    DAT_00423608 = 0;
    DAT_0042360A = 0;
    DAT_0042360E = 0;
    return 0;
}
