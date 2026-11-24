// bin: proto
// va: 0x002F0C50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0C50 (Proto 0x002F0C50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003F5CB8;
extern "C" int DAT_003F5CBC;
extern "C" unsigned short DAT_003F5CC4;
extern "C" unsigned short DAT_003F5CC6;
extern "C" unsigned short DAT_003F5CCA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F0C50(void)
{
    DAT_003F5CB8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003F5CBC);
    DAT_003F5CBC = 0;
    DAT_003F5CC4 = 0;
    DAT_003F5CC6 = 0;
    DAT_003F5CCA = 0;
    return 0;
}
