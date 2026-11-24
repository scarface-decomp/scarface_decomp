// bin: xb
// va: 0x003290A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003290A0 (0x003290A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044D490;
extern "C" int DAT_0044D494;
extern "C" unsigned short DAT_0044D49C;
extern "C" unsigned short DAT_0044D49E;
extern "C" unsigned short DAT_0044D4A2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003290A0(void)
{
    DAT_0044D490 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044D494);
    DAT_0044D494 = 0;
    DAT_0044D49C = 0;
    DAT_0044D49E = 0;
    DAT_0044D4A2 = 0;
    return 0;
}
