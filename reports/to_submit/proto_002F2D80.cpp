// bin: proto
// va: 0x002F2D80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2D80 (Proto 0x002F2D80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409CB4;
extern "C" int DAT_00409CB8;
extern "C" unsigned short DAT_00409CC0;
extern "C" unsigned short DAT_00409CC2;
extern "C" unsigned short DAT_00409CC6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2D80(void)
{
    DAT_00409CB4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409CB8);
    DAT_00409CB8 = 0;
    DAT_00409CC0 = 0;
    DAT_00409CC2 = 0;
    DAT_00409CC6 = 0;
    return 0;
}
