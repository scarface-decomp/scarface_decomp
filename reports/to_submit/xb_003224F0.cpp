// bin: xb
// va: 0x003224F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003224F0 (0x003224F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004191CC;
extern "C" int DAT_004191D0;
extern "C" unsigned short DAT_004191D8;
extern "C" unsigned short DAT_004191DA;
extern "C" unsigned short DAT_004191DE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003224F0(void)
{
    DAT_004191CC = (int)DAT_0039D4E4;
    sub_00027600(DAT_004191D0);
    DAT_004191D0 = 0;
    DAT_004191D8 = 0;
    DAT_004191DA = 0;
    DAT_004191DE = 0;
    return 0;
}
