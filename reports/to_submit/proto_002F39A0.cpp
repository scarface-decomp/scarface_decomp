// bin: proto
// va: 0x002F39A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F39A0 (Proto 0x002F39A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041052C;
extern "C" int DAT_00410530;
extern "C" unsigned short DAT_00410538;
extern "C" unsigned short DAT_0041053A;
extern "C" unsigned short DAT_0041053E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F39A0(void)
{
    DAT_0041052C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410530);
    DAT_00410530 = 0;
    DAT_00410538 = 0;
    DAT_0041053A = 0;
    DAT_0041053E = 0;
    return 0;
}
