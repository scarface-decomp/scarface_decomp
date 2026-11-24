// bin: proto
// va: 0x002F1160
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1160 (Proto 0x002F1160, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F8C18;
extern "C" unsigned short DAT_003F8C20;
extern "C" unsigned short DAT_003F8C22;
extern "C" unsigned short DAT_003F8C26;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1160(void)
{
    sub_00025160(DAT_003F8C18);
    DAT_003F8C18 = 0;
    DAT_003F8C20 = 0;
    DAT_003F8C22 = 0;
    DAT_003F8C26 = 0;
    return 0;
}
