// bin: proto
// va: 0x002F5100
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5100 (Proto 0x002F5100, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417290;
extern "C" int DAT_00417294;
extern "C" unsigned short DAT_0041729C;
extern "C" unsigned short DAT_0041729E;
extern "C" unsigned short DAT_004172A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5100(void)
{
    DAT_00417290 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417294);
    DAT_00417294 = 0;
    DAT_0041729C = 0;
    DAT_0041729E = 0;
    DAT_004172A2 = 0;
    return 0;
}
