// bin: xb
// va: 0x00329120
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329120 (0x00329120, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044D584;
extern "C" int DAT_0044D588;
extern "C" unsigned short DAT_0044D590;
extern "C" unsigned short DAT_0044D592;
extern "C" unsigned short DAT_0044D596;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00329120(void)
{
    DAT_0044D584 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044D588);
    DAT_0044D588 = 0;
    DAT_0044D590 = 0;
    DAT_0044D592 = 0;
    DAT_0044D596 = 0;
    return 0;
}
