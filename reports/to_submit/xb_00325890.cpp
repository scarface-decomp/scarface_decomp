// bin: xb
// va: 0x00325890
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00325890 (0x00325890, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00436E04;
extern "C" int DAT_00436E08;
extern "C" unsigned short DAT_00436E10;
extern "C" unsigned short DAT_00436E12;
extern "C" unsigned short DAT_00436E16;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00325890(void)
{
    DAT_00436E04 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00436E08);
    DAT_00436E08 = 0;
    DAT_00436E10 = 0;
    DAT_00436E12 = 0;
    DAT_00436E16 = 0;
    return 0;
}
