// bin: proto
// va: 0x002F4900
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4900 (Proto 0x002F4900, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413EB0;
extern "C" int DAT_00413EB4;
extern "C" unsigned short DAT_00413EBC;
extern "C" unsigned short DAT_00413EBE;
extern "C" unsigned short DAT_00413EC2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4900(void)
{
    DAT_00413EB0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413EB4);
    DAT_00413EB4 = 0;
    DAT_00413EBC = 0;
    DAT_00413EBE = 0;
    DAT_00413EC2 = 0;
    return 0;
}
