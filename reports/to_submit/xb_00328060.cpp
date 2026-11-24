// bin: xb
// va: 0x00328060
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328060 (0x00328060, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00445CF0;
extern "C" int DAT_00445CF4;
extern "C" unsigned short DAT_00445CFC;
extern "C" unsigned short DAT_00445CFE;
extern "C" unsigned short DAT_00445D02;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328060(void)
{
    DAT_00445CF0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00445CF4);
    DAT_00445CF4 = 0;
    DAT_00445CFC = 0;
    DAT_00445CFE = 0;
    DAT_00445D02 = 0;
    return 0;
}
