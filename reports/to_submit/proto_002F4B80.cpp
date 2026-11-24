// bin: proto
// va: 0x002F4B80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4B80 (Proto 0x002F4B80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00414C4C;
extern "C" int DAT_00414C50;
extern "C" unsigned short DAT_00414C58;
extern "C" unsigned short DAT_00414C5A;
extern "C" unsigned short DAT_00414C5E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4B80(void)
{
    DAT_00414C4C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00414C50);
    DAT_00414C50 = 0;
    DAT_00414C58 = 0;
    DAT_00414C5A = 0;
    DAT_00414C5E = 0;
    return 0;
}
