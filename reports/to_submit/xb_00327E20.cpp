// bin: xb
// va: 0x00327E20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00327E20 (0x00327E20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_004445B0;
extern "C" int DAT_004445B4;
extern "C" unsigned short DAT_004445BC;
extern "C" unsigned short DAT_004445BE;
extern "C" unsigned short DAT_004445C2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00327E20(void)
{
    DAT_004445B0 = (int)DAT_0039D4E4;
    sub_00027600(DAT_004445B4);
    DAT_004445B4 = 0;
    DAT_004445BC = 0;
    DAT_004445BE = 0;
    DAT_004445C2 = 0;
    return 0;
}
