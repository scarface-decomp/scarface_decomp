// bin: proto
// va: 0x002F0A90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0A90 (Proto 0x002F0A90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5B84;
extern "C" int DAT_003F5B88;
extern "C" unsigned short DAT_003F5B90;
extern "C" unsigned short DAT_003F5B92;
extern "C" unsigned short DAT_003F5B96;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0A90(void)
{
    DAT_003F5B84 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5B88);
    DAT_003F5B88 = 0;
    DAT_003F5B90 = 0;
    DAT_003F5B92 = 0;
    DAT_003F5B96 = 0;
    return 0;
}
