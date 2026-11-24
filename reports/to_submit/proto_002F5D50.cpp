// bin: proto
// va: 0x002F5D50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5D50 (Proto 0x002F5D50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041A924;
extern "C" int DAT_0041A928;
extern "C" unsigned short DAT_0041A930;
extern "C" unsigned short DAT_0041A932;
extern "C" unsigned short DAT_0041A936;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5D50(void)
{
    DAT_0041A924 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041A928);
    DAT_0041A928 = 0;
    DAT_0041A930 = 0;
    DAT_0041A932 = 0;
    DAT_0041A936 = 0;
    return 0;
}
