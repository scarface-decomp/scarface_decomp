// bin: proto
// va: 0x002F0D10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0D10 (Proto 0x002F0D10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5D3C;
extern "C" int DAT_003F5D40;
extern "C" unsigned short DAT_003F5D48;
extern "C" unsigned short DAT_003F5D4A;
extern "C" unsigned short DAT_003F5D4E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0D10(void)
{
    DAT_003F5D3C = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5D40);
    DAT_003F5D40 = 0;
    DAT_003F5D48 = 0;
    DAT_003F5D4A = 0;
    DAT_003F5D4E = 0;
    return 0;
}
