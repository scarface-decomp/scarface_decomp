// bin: xb
// va: 0x00325110
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325110 (0x00325110, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00434074;
extern "C" int DAT_00434078;
extern "C" unsigned short DAT_00434080;
extern "C" unsigned short DAT_00434082;
extern "C" unsigned short DAT_00434086;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325110(void)
{
    DAT_00434074 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00434078);
    DAT_00434078 = 0;
    DAT_00434080 = 0;
    DAT_00434082 = 0;
    DAT_00434086 = 0;
    return 0;
}
