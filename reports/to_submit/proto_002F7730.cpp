// bin: proto
// va: 0x002F7730
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7730 (Proto 0x002F7730, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00427124;
extern "C" int DAT_00427128;
extern "C" unsigned short DAT_00427130;
extern "C" unsigned short DAT_00427132;
extern "C" unsigned short DAT_00427136;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7730(void)
{
    DAT_00427124 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00427128);
    DAT_00427128 = 0;
    DAT_00427130 = 0;
    DAT_00427132 = 0;
    DAT_00427136 = 0;
    return 0;
}
