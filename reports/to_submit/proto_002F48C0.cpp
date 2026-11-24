// bin: proto
// va: 0x002F48C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F48C0 (Proto 0x002F48C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413D98;
extern "C" int DAT_00413D9C;
extern "C" unsigned short DAT_00413DA4;
extern "C" unsigned short DAT_00413DA6;
extern "C" unsigned short DAT_00413DAA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F48C0(void)
{
    DAT_00413D98 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413D9C);
    DAT_00413D9C = 0;
    DAT_00413DA4 = 0;
    DAT_00413DA6 = 0;
    DAT_00413DAA = 0;
    return 0;
}
