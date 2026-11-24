// bin: proto
// va: 0x002F64F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F64F0 (Proto 0x002F64F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041DFAC;
extern "C" int DAT_0041DFB0;
extern "C" unsigned short DAT_0041DFB8;
extern "C" unsigned short DAT_0041DFBA;
extern "C" unsigned short DAT_0041DFBE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F64F0(void)
{
    DAT_0041DFAC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041DFB0);
    DAT_0041DFB0 = 0;
    DAT_0041DFB8 = 0;
    DAT_0041DFBA = 0;
    DAT_0041DFBE = 0;
    return 0;
}
