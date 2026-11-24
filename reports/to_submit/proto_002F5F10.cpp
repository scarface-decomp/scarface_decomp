// bin: proto
// va: 0x002F5F10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5F10 (Proto 0x002F5F10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041AEBC;
extern "C" int DAT_0041AEC0;
extern "C" unsigned short DAT_0041AEC8;
extern "C" unsigned short DAT_0041AECA;
extern "C" unsigned short DAT_0041AECE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5F10(void)
{
    DAT_0041AEBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041AEC0);
    DAT_0041AEC0 = 0;
    DAT_0041AEC8 = 0;
    DAT_0041AECA = 0;
    DAT_0041AECE = 0;
    return 0;
}
