// bin: proto
// va: 0x002F0A00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0A00 (Proto 0x002F0A00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F4EBC;
extern "C" int DAT_003F4EC0;
extern "C" unsigned short DAT_003F4EC8;
extern "C" unsigned short DAT_003F4ECA;
extern "C" unsigned short DAT_003F4ECE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0A00(void)
{
    DAT_003F4EBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F4EC0);
    DAT_003F4EC0 = 0;
    DAT_003F4EC8 = 0;
    DAT_003F4ECA = 0;
    DAT_003F4ECE = 0;
    return 0;
}
