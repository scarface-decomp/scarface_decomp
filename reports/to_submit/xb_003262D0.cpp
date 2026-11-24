// bin: xb
// va: 0x003262D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003262D0 (0x003262D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00439DFC;
extern "C" int DAT_00439E00;
extern "C" unsigned short DAT_00439E08;
extern "C" unsigned short DAT_00439E0A;
extern "C" unsigned short DAT_00439E0E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003262D0(void)
{
    DAT_00439DFC = (int)DAT_0039D4E4;
    sub_00027600(DAT_00439E00);
    DAT_00439E00 = 0;
    DAT_00439E08 = 0;
    DAT_00439E0A = 0;
    DAT_00439E0E = 0;
    return 0;
}
