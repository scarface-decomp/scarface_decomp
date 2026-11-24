// bin: xb
// va: 0x00327940
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327940 (0x00327940, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004415F8;
extern "C" int DAT_004415FC;
extern "C" unsigned short DAT_00441604;
extern "C" unsigned short DAT_00441606;
extern "C" unsigned short DAT_0044160A;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327940(void)
{
    DAT_004415F8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004415FC);
    DAT_004415FC = 0;
    DAT_00441604 = 0;
    DAT_00441606 = 0;
    DAT_0044160A = 0;
    return 0;
}
