// bin: proto
// va: 0x002F29B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F29B0 (Proto 0x002F29B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040909C;
extern "C" int DAT_004090A0;
extern "C" unsigned short DAT_004090A8;
extern "C" unsigned short DAT_004090AA;
extern "C" unsigned short DAT_004090AE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F29B0(void)
{
    DAT_0040909C = (int)DAT_0037CCF4;
    sub_00025160(DAT_004090A0);
    DAT_004090A0 = 0;
    DAT_004090A8 = 0;
    DAT_004090AA = 0;
    DAT_004090AE = 0;
    return 0;
}
