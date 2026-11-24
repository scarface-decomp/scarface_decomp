// bin: proto
// va: 0x002F0B10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0B10 (Proto 0x002F0B10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5BDC;
extern "C" int DAT_003F5BE0;
extern "C" unsigned short DAT_003F5BE8;
extern "C" unsigned short DAT_003F5BEA;
extern "C" unsigned short DAT_003F5BEE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0B10(void)
{
    DAT_003F5BDC = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5BE0);
    DAT_003F5BE0 = 0;
    DAT_003F5BE8 = 0;
    DAT_003F5BEA = 0;
    DAT_003F5BEE = 0;
    return 0;
}
