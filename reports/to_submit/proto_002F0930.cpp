// bin: proto
// va: 0x002F0930
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0930 (Proto 0x002F0930, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F41B0;
extern "C" int DAT_003F41B4;
extern "C" unsigned short DAT_003F41BC;
extern "C" unsigned short DAT_003F41BE;
extern "C" unsigned short DAT_003F41C2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0930(void)
{
    DAT_003F41B0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F41B4);
    DAT_003F41B4 = 0;
    DAT_003F41BC = 0;
    DAT_003F41BE = 0;
    DAT_003F41C2 = 0;
    return 0;
}
