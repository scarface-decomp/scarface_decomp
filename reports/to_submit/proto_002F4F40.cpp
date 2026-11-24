// bin: proto
// va: 0x002F4F40
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4F40 (Proto 0x002F4F40, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041715C;
extern "C" int DAT_00417160;
extern "C" unsigned short DAT_00417168;
extern "C" unsigned short DAT_0041716A;
extern "C" unsigned short DAT_0041716E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4F40(void)
{
    DAT_0041715C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417160);
    DAT_00417160 = 0;
    DAT_00417168 = 0;
    DAT_0041716A = 0;
    DAT_0041716E = 0;
    return 0;
}
