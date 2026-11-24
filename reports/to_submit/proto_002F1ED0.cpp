// bin: proto
// va: 0x002F1ED0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1ED0 (Proto 0x002F1ED0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403ED0;
extern "C" int DAT_00403ED4;
extern "C" unsigned short DAT_00403EDC;
extern "C" unsigned short DAT_00403EDE;
extern "C" unsigned short DAT_00403EE2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1ED0(void)
{
    DAT_00403ED0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403ED4);
    DAT_00403ED4 = 0;
    DAT_00403EDC = 0;
    DAT_00403EDE = 0;
    DAT_00403EE2 = 0;
    return 0;
}
