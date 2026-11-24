// bin: xb
// va: 0x003258D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003258D0 (0x003258D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436E7C;
extern "C" int DAT_00436E80;
extern "C" unsigned short DAT_00436E88;
extern "C" unsigned short DAT_00436E8A;
extern "C" unsigned short DAT_00436E8E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003258D0(void)
{
    DAT_00436E7C = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436E80);
    DAT_00436E80 = 0;
    DAT_00436E88 = 0;
    DAT_00436E8A = 0;
    DAT_00436E8E = 0;
    return 0;
}
