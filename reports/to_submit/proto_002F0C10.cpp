// bin: proto
// va: 0x002F0C10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0C10 (Proto 0x002F0C10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5C8C;
extern "C" int DAT_003F5C90;
extern "C" unsigned short DAT_003F5C98;
extern "C" unsigned short DAT_003F5C9A;
extern "C" unsigned short DAT_003F5C9E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0C10(void)
{
    DAT_003F5C8C = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5C90);
    DAT_003F5C90 = 0;
    DAT_003F5C98 = 0;
    DAT_003F5C9A = 0;
    DAT_003F5C9E = 0;
    return 0;
}
