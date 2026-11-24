// bin: xb
// va: 0x00328D60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328D60 (0x00328D60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044C068;
extern "C" int DAT_0044C06C;
extern "C" unsigned short DAT_0044C074;
extern "C" unsigned short DAT_0044C076;
extern "C" unsigned short DAT_0044C07A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328D60(void)
{
    DAT_0044C068 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044C06C);
    DAT_0044C06C = 0;
    DAT_0044C074 = 0;
    DAT_0044C076 = 0;
    DAT_0044C07A = 0;
    return 0;
}
