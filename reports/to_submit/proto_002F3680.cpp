// bin: proto
// va: 0x002F3680
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3680 (Proto 0x002F3680, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040F0A0;
extern "C" int DAT_0040F0A4;
extern "C" unsigned short DAT_0040F0AC;
extern "C" unsigned short DAT_0040F0AE;
extern "C" unsigned short DAT_0040F0B2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3680(void)
{
    DAT_0040F0A0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040F0A4);
    DAT_0040F0A4 = 0;
    DAT_0040F0AC = 0;
    DAT_0040F0AE = 0;
    DAT_0040F0B2 = 0;
    return 0;
}
