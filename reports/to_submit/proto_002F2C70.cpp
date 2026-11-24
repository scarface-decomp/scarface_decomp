// bin: proto
// va: 0x002F2C70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2C70 (Proto 0x002F2C70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004096AC;
extern "C" int DAT_004096B0;
extern "C" unsigned short DAT_004096B8;
extern "C" unsigned short DAT_004096BA;
extern "C" unsigned short DAT_004096BE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2C70(void)
{
    DAT_004096AC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004096B0);
    DAT_004096B0 = 0;
    DAT_004096B8 = 0;
    DAT_004096BA = 0;
    DAT_004096BE = 0;
    return 0;
}
