// bin: proto
// va: 0x002F0970
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0970 (Proto 0x002F0970, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F41DC;
extern "C" int DAT_003F41E0;
extern "C" unsigned short DAT_003F41E8;
extern "C" unsigned short DAT_003F41EA;
extern "C" unsigned short DAT_003F41EE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0970(void)
{
    DAT_003F41DC = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F41E0);
    DAT_003F41E0 = 0;
    DAT_003F41E8 = 0;
    DAT_003F41EA = 0;
    DAT_003F41EE = 0;
    return 0;
}
