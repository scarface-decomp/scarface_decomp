// bin: proto
// va: 0x002F4220
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4220 (Proto 0x002F4220, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411BD8;
extern "C" int DAT_00411BDC;
extern "C" unsigned short DAT_00411BE4;
extern "C" unsigned short DAT_00411BE6;
extern "C" unsigned short DAT_00411BEA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4220(void)
{
    DAT_00411BD8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411BDC);
    DAT_00411BDC = 0;
    DAT_00411BE4 = 0;
    DAT_00411BE6 = 0;
    DAT_00411BEA = 0;
    return 0;
}
