// bin: proto
// va: 0x002F0E30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0E30 (Proto 0x002F0E30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F661C;
extern "C" int DAT_003F6620;
extern "C" unsigned short DAT_003F6628;
extern "C" unsigned short DAT_003F662A;
extern "C" unsigned short DAT_003F662E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0E30(void)
{
    DAT_003F661C = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6620);
    DAT_003F6620 = 0;
    DAT_003F6628 = 0;
    DAT_003F662A = 0;
    DAT_003F662E = 0;
    return 0;
}
