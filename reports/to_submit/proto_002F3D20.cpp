// bin: proto
// va: 0x002F3D20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3D20 (Proto 0x002F3D20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410D28;
extern "C" int DAT_00410D2C;
extern "C" unsigned short DAT_00410D34;
extern "C" unsigned short DAT_00410D36;
extern "C" unsigned short DAT_00410D3A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3D20(void)
{
    DAT_00410D28 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410D2C);
    DAT_00410D2C = 0;
    DAT_00410D34 = 0;
    DAT_00410D36 = 0;
    DAT_00410D3A = 0;
    return 0;
}
