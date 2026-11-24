// bin: proto
// va: 0x002F1030
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1030 (Proto 0x002F1030, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F6BC8;
extern "C" int DAT_003F6BCC;
extern "C" unsigned short DAT_003F6BD4;
extern "C" unsigned short DAT_003F6BD6;
extern "C" unsigned short DAT_003F6BDA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1030(void)
{
    DAT_003F6BC8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F6BCC);
    DAT_003F6BCC = 0;
    DAT_003F6BD4 = 0;
    DAT_003F6BD6 = 0;
    DAT_003F6BDA = 0;
    return 0;
}
