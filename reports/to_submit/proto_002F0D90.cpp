// bin: proto
// va: 0x002F0D90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0D90 (Proto 0x002F0D90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F6104;
extern "C" int DAT_003F6108;
extern "C" unsigned short DAT_003F6110;
extern "C" unsigned short DAT_003F6112;
extern "C" unsigned short DAT_003F6116;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0D90(void)
{
    DAT_003F6104 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6108);
    DAT_003F6108 = 0;
    DAT_003F6110 = 0;
    DAT_003F6112 = 0;
    DAT_003F6116 = 0;
    return 0;
}
