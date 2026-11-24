// bin: proto
// va: 0x002F0EB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0EB0 (Proto 0x002F0EB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F67C4;
extern "C" int DAT_003F67C8;
extern "C" unsigned short DAT_003F67D0;
extern "C" unsigned short DAT_003F67D2;
extern "C" unsigned short DAT_003F67D6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0EB0(void)
{
    DAT_003F67C4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F67C8);
    DAT_003F67C8 = 0;
    DAT_003F67D0 = 0;
    DAT_003F67D2 = 0;
    DAT_003F67D6 = 0;
    return 0;
}
