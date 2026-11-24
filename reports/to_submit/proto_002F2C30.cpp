// bin: proto
// va: 0x002F2C30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2C30 (Proto 0x002F2C30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004095A8;
extern "C" int DAT_004095AC;
extern "C" unsigned short DAT_004095B4;
extern "C" unsigned short DAT_004095B6;
extern "C" unsigned short DAT_004095BA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2C30(void)
{
    DAT_004095A8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004095AC);
    DAT_004095AC = 0;
    DAT_004095B4 = 0;
    DAT_004095B6 = 0;
    DAT_004095BA = 0;
    return 0;
}
