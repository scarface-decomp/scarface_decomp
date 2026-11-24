// bin: xb
// va: 0x00328260
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00328260 (0x00328260, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004477C8;
extern "C" int DAT_004477CC;
extern "C" unsigned short DAT_004477D4;
extern "C" unsigned short DAT_004477D6;
extern "C" unsigned short DAT_004477DA;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00328260(void)
{
    DAT_004477C8 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004477CC);
    DAT_004477CC = 0;
    DAT_004477D4 = 0;
    DAT_004477D6 = 0;
    DAT_004477DA = 0;
    return 0;
}
