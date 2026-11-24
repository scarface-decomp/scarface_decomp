// bin: proto
// va: 0x002F2290
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2290 (Proto 0x002F2290, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404164;
extern "C" int DAT_00404168;
extern "C" unsigned short DAT_00404170;
extern "C" unsigned short DAT_00404172;
extern "C" unsigned short DAT_00404176;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2290(void)
{
    DAT_00404164 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404168);
    DAT_00404168 = 0;
    DAT_00404170 = 0;
    DAT_00404172 = 0;
    DAT_00404176 = 0;
    return 0;
}
