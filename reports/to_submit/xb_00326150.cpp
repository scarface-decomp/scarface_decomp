// bin: xb
// va: 0x00326150
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326150 (0x00326150, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439CF4;
extern "C" int DAT_00439CF8;
extern "C" unsigned short DAT_00439D00;
extern "C" unsigned short DAT_00439D02;
extern "C" unsigned short DAT_00439D06;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00326150(void)
{
    DAT_00439CF4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439CF8);
    DAT_00439CF8 = 0;
    DAT_00439D00 = 0;
    DAT_00439D02 = 0;
    DAT_00439D06 = 0;
    return 0;
}
