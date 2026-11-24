// bin: proto
// va: 0x002F40E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F40E0 (Proto 0x002F40E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041196C;
extern "C" int DAT_00411970;
extern "C" unsigned short DAT_00411978;
extern "C" unsigned short DAT_0041197A;
extern "C" unsigned short DAT_0041197E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F40E0(void)
{
    DAT_0041196C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411970);
    DAT_00411970 = 0;
    DAT_00411978 = 0;
    DAT_0041197A = 0;
    DAT_0041197E = 0;
    return 0;
}
