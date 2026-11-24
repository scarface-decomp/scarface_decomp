// bin: proto
// va: 0x002F0B50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0B50 (Proto 0x002F0B50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5C08;
extern "C" int DAT_003F5C0C;
extern "C" unsigned short DAT_003F5C14;
extern "C" unsigned short DAT_003F5C16;
extern "C" unsigned short DAT_003F5C1A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0B50(void)
{
    DAT_003F5C08 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5C0C);
    DAT_003F5C0C = 0;
    DAT_003F5C14 = 0;
    DAT_003F5C16 = 0;
    DAT_003F5C1A = 0;
    return 0;
}
