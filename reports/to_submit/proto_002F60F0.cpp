// bin: proto
// va: 0x002F60F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F60F0 (Proto 0x002F60F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041BDC0;
extern "C" int DAT_0041BDC4;
extern "C" unsigned short DAT_0041BDCC;
extern "C" unsigned short DAT_0041BDCE;
extern "C" unsigned short DAT_0041BDD2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F60F0(void)
{
    DAT_0041BDC0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041BDC4);
    DAT_0041BDC4 = 0;
    DAT_0041BDCC = 0;
    DAT_0041BDCE = 0;
    DAT_0041BDD2 = 0;
    return 0;
}
