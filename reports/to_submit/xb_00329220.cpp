// bin: xb
// va: 0x00329220
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329220 (0x00329220, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044DE2C;
extern "C" int DAT_0044DE30;
extern "C" unsigned short DAT_0044DE38;
extern "C" unsigned short DAT_0044DE3A;
extern "C" unsigned short DAT_0044DE3E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00329220(void)
{
    DAT_0044DE2C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044DE30);
    DAT_0044DE30 = 0;
    DAT_0044DE38 = 0;
    DAT_0044DE3A = 0;
    DAT_0044DE3E = 0;
    return 0;
}
