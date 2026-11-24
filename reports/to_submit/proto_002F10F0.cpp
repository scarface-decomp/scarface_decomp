// bin: proto
// va: 0x002F10F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F10F0 (Proto 0x002F10F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F6F68;
extern "C" int DAT_003F6F6C;
extern "C" unsigned short DAT_003F6F74;
extern "C" unsigned short DAT_003F6F76;
extern "C" unsigned short DAT_003F6F7A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F10F0(void)
{
    DAT_003F6F68 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6F6C);
    DAT_003F6F6C = 0;
    DAT_003F6F74 = 0;
    DAT_003F6F76 = 0;
    DAT_003F6F7A = 0;
    return 0;
}
