// bin: proto
// va: 0x002F2150
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2150 (Proto 0x002F2150, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404088;
extern "C" int DAT_0040408C;
extern "C" unsigned short DAT_00404094;
extern "C" unsigned short DAT_00404096;
extern "C" unsigned short DAT_0040409A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2150(void)
{
    DAT_00404088 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040408C);
    DAT_0040408C = 0;
    DAT_00404094 = 0;
    DAT_00404096 = 0;
    DAT_0040409A = 0;
    return 0;
}
