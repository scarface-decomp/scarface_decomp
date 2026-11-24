// bin: proto
// va: 0x002F0F30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0F30 (Proto 0x002F0F30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F6A40;
extern "C" int DAT_003F6A44;
extern "C" unsigned short DAT_003F6A4C;
extern "C" unsigned short DAT_003F6A4E;
extern "C" unsigned short DAT_003F6A52;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0F30(void)
{
    DAT_003F6A40 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6A44);
    DAT_003F6A44 = 0;
    DAT_003F6A4C = 0;
    DAT_003F6A4E = 0;
    DAT_003F6A52 = 0;
    return 0;
}
