// bin: xb
// va: 0x00327140
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327140 (0x00327140, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0043E4C8;
extern "C" int DAT_0043E4CC;
extern "C" unsigned short DAT_0043E4D4;
extern "C" unsigned short DAT_0043E4D6;
extern "C" unsigned short DAT_0043E4DA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327140(void)
{
    DAT_0043E4C8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0043E4CC);
    DAT_0043E4CC = 0;
    DAT_0043E4D4 = 0;
    DAT_0043E4D6 = 0;
    DAT_0043E4DA = 0;
    return 0;
}
