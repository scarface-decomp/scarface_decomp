// bin: proto
// va: 0x002F4520
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4520 (Proto 0x002F4520, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004133DC;
extern "C" int DAT_004133E0;
extern "C" unsigned short DAT_004133E8;
extern "C" unsigned short DAT_004133EA;
extern "C" unsigned short DAT_004133EE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4520(void)
{
    DAT_004133DC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004133E0);
    DAT_004133E0 = 0;
    DAT_004133E8 = 0;
    DAT_004133EA = 0;
    DAT_004133EE = 0;
    return 0;
}
