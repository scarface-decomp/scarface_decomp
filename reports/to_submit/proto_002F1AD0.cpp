// bin: proto
// va: 0x002F1AD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1AD0 (Proto 0x002F1AD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403C10;
extern "C" int DAT_00403C14;
extern "C" unsigned short DAT_00403C1C;
extern "C" unsigned short DAT_00403C1E;
extern "C" unsigned short DAT_00403C22;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1AD0(void)
{
    DAT_00403C10 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403C14);
    DAT_00403C14 = 0;
    DAT_00403C1C = 0;
    DAT_00403C1E = 0;
    DAT_00403C22 = 0;
    return 0;
}
