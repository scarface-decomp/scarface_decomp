// bin: proto
// va: 0x002F1210
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1210 (Proto 0x002F1210, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F9DD8;
extern "C" unsigned short DAT_003F9DE0;
extern "C" unsigned short DAT_003F9DE2;
extern "C" unsigned short DAT_003F9DE6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1210(void)
{
    sub_00025160(DAT_003F9DD8);
    DAT_003F9DD8 = 0;
    DAT_003F9DE0 = 0;
    DAT_003F9DE2 = 0;
    DAT_003F9DE6 = 0;
    return 0;
}
