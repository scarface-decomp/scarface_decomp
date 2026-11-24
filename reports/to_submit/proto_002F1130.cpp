// bin: proto
// va: 0x002F1130
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1130 (Proto 0x002F1130, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_003F7394;
extern "C" unsigned short DAT_003F739C;
extern "C" unsigned short DAT_003F739E;
extern "C" unsigned short DAT_003F73A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1130(void)
{
    sub_00025160(DAT_003F7394);
    DAT_003F7394 = 0;
    DAT_003F739C = 0;
    DAT_003F739E = 0;
    DAT_003F73A2 = 0;
    return 0;
}
