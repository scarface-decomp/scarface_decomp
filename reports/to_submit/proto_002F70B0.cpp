// bin: proto
// va: 0x002F70B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F70B0 (Proto 0x002F70B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00424610;
extern "C" int DAT_00424614;
extern "C" unsigned short DAT_0042461C;
extern "C" unsigned short DAT_0042461E;
extern "C" unsigned short DAT_00424622;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F70B0(void)
{
    DAT_00424610 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00424614);
    DAT_00424614 = 0;
    DAT_0042461C = 0;
    DAT_0042461E = 0;
    DAT_00424622 = 0;
    return 0;
}
