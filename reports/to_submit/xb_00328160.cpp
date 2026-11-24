// bin: xb
// va: 0x00328160
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328160 (0x00328160, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00447718;
extern "C" int DAT_0044771C;
extern "C" unsigned short DAT_00447724;
extern "C" unsigned short DAT_00447726;
extern "C" unsigned short DAT_0044772A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328160(void)
{
    DAT_00447718 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044771C);
    DAT_0044771C = 0;
    DAT_00447724 = 0;
    DAT_00447726 = 0;
    DAT_0044772A = 0;
    return 0;
}
