// bin: proto
// va: 0x002F4C00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4C00 (Proto 0x002F4C00, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00414DFC;
extern "C" int DAT_00414E00;
extern "C" unsigned short DAT_00414E08;
extern "C" unsigned short DAT_00414E0A;
extern "C" unsigned short DAT_00414E0E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4C00(void)
{
    DAT_00414DFC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00414E00);
    DAT_00414E00 = 0;
    DAT_00414E08 = 0;
    DAT_00414E0A = 0;
    DAT_00414E0E = 0;
    return 0;
}
