// bin: proto
// va: 0x002F0D50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0D50 (Proto 0x002F0D50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5D68;
extern "C" int DAT_003F5D6C;
extern "C" unsigned short DAT_003F5D74;
extern "C" unsigned short DAT_003F5D76;
extern "C" unsigned short DAT_003F5D7A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0D50(void)
{
    DAT_003F5D68 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5D6C);
    DAT_003F5D6C = 0;
    DAT_003F5D74 = 0;
    DAT_003F5D76 = 0;
    DAT_003F5D7A = 0;
    return 0;
}
