// bin: xb
// va: 0x00327BA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327BA0 (0x00327BA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_00442580;
extern "C" int DAT_00442584;
extern "C" unsigned short DAT_0044258C;
extern "C" unsigned short DAT_0044258E;
extern "C" unsigned short DAT_00442592;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327BA0(void)
{
    DAT_00442580 = (int)DAT_0039D4E4;
    sub_00027600(DAT_00442584);
    DAT_00442584 = 0;
    DAT_0044258C = 0;
    DAT_0044258E = 0;
    DAT_00442592 = 0;
    return 0;
}
