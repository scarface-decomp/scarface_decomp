// bin: proto
// va: 0x002F1070
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1070 (Proto 0x002F1070, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F6D24;
extern "C" int DAT_003F6D28;
extern "C" unsigned short DAT_003F6D30;
extern "C" unsigned short DAT_003F6D32;
extern "C" unsigned short DAT_003F6D36;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1070(void)
{
    DAT_003F6D24 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6D28);
    DAT_003F6D28 = 0;
    DAT_003F6D30 = 0;
    DAT_003F6D32 = 0;
    DAT_003F6D36 = 0;
    return 0;
}
