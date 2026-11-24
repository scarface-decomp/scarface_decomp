// bin: xb
// va: 0x00328DE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328DE0 (0x00328DE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0044C0C0;
extern "C" int DAT_0044C0C4;
extern "C" unsigned short DAT_0044C0CC;
extern "C" unsigned short DAT_0044C0CE;
extern "C" unsigned short DAT_0044C0D2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328DE0(void)
{
    DAT_0044C0C0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0044C0C4);
    DAT_0044C0C4 = 0;
    DAT_0044C0CC = 0;
    DAT_0044C0CE = 0;
    DAT_0044C0D2 = 0;
    return 0;
}
