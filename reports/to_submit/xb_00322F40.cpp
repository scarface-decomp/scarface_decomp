// bin: xb
// va: 0x00322F40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322F40 (0x00322F40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004234A4;
extern "C" int DAT_004234A8;
extern "C" unsigned short DAT_004234B0;
extern "C" unsigned short DAT_004234B2;
extern "C" unsigned short DAT_004234B6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322F40(void)
{
    DAT_004234A4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004234A8);
    DAT_004234A8 = 0;
    DAT_004234B0 = 0;
    DAT_004234B2 = 0;
    DAT_004234B6 = 0;
    return 0;
}
