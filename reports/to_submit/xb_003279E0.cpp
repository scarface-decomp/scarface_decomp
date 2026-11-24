// bin: xb
// va: 0x003279E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003279E0 (0x003279E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00442094;
extern "C" int DAT_00442098;
extern "C" unsigned short DAT_004420A0;
extern "C" unsigned short DAT_004420A2;
extern "C" unsigned short DAT_004420A6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003279E0(void)
{
    DAT_00442094 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00442098);
    DAT_00442098 = 0;
    DAT_004420A0 = 0;
    DAT_004420A2 = 0;
    DAT_004420A6 = 0;
    return 0;
}
