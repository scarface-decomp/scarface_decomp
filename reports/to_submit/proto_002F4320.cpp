// bin: proto
// va: 0x002F4320
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4320 (Proto 0x002F4320, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411DDC;
extern "C" int DAT_00411DE0;
extern "C" unsigned short DAT_00411DE8;
extern "C" unsigned short DAT_00411DEA;
extern "C" unsigned short DAT_00411DEE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4320(void)
{
    DAT_00411DDC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411DE0);
    DAT_00411DE0 = 0;
    DAT_00411DE8 = 0;
    DAT_00411DEA = 0;
    DAT_00411DEE = 0;
    return 0;
}
