// bin: xb
// va: 0x003279A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003279A0 (0x003279A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00441A00;
extern "C" int DAT_00441A04;
extern "C" unsigned short DAT_00441A0C;
extern "C" unsigned short DAT_00441A0E;
extern "C" unsigned short DAT_00441A12;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003279A0(void)
{
    DAT_00441A00 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00441A04);
    DAT_00441A04 = 0;
    DAT_00441A0C = 0;
    DAT_00441A0E = 0;
    DAT_00441A12 = 0;
    return 0;
}
