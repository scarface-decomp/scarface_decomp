// bin: proto
// va: 0x002F0AD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0AD0 (Proto 0x002F0AD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5BB0;
extern "C" int DAT_003F5BB4;
extern "C" unsigned short DAT_003F5BBC;
extern "C" unsigned short DAT_003F5BBE;
extern "C" unsigned short DAT_003F5BC2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0AD0(void)
{
    DAT_003F5BB0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5BB4);
    DAT_003F5BB4 = 0;
    DAT_003F5BBC = 0;
    DAT_003F5BBE = 0;
    DAT_003F5BC2 = 0;
    return 0;
}
