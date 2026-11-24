// bin: proto
// va: 0x002F0B90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0B90 (Proto 0x002F0B90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5C34;
extern "C" int DAT_003F5C38;
extern "C" unsigned short DAT_003F5C40;
extern "C" unsigned short DAT_003F5C42;
extern "C" unsigned short DAT_003F5C46;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0B90(void)
{
    DAT_003F5C34 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5C38);
    DAT_003F5C38 = 0;
    DAT_003F5C40 = 0;
    DAT_003F5C42 = 0;
    DAT_003F5C46 = 0;
    return 0;
}
