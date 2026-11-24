// bin: xb
// va: 0x00314830
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314830 (0x00314830, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A41D4[];
extern "C" char DAT_003A41E4[];
extern "C" char DAT_003A41F4[];
extern "C" int DAT_004815DC;
extern "C" int DAT_004815E0;
extern "C" int DAT_004815E4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00314830(void)
{
    DAT_004815DC = sub_00244040((int)DAT_003A41F4, 0);
    DAT_004815E0 = sub_00244040((int)DAT_003A41E4, 0);
    DAT_004815E4 = sub_00244040((int)DAT_003A41D4, 0);
}
