// bin: proto
// va: 0x002F3150
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3150 (Proto 0x002F3150, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040AEBC;
extern "C" int DAT_0040AEC0;
extern "C" unsigned short DAT_0040AEC8;
extern "C" unsigned short DAT_0040AECA;
extern "C" unsigned short DAT_0040AECE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3150(void)
{
    DAT_0040AEBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040AEC0);
    DAT_0040AEC0 = 0;
    DAT_0040AEC8 = 0;
    DAT_0040AECA = 0;
    DAT_0040AECE = 0;
    return 0;
}
