// bin: proto
// va: 0x002F2450
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2450 (Proto 0x002F2450, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404298;
extern "C" int DAT_0040429C;
extern "C" unsigned short DAT_004042A4;
extern "C" unsigned short DAT_004042A6;
extern "C" unsigned short DAT_004042AA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2450(void)
{
    DAT_00404298 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040429C);
    DAT_0040429C = 0;
    DAT_004042A4 = 0;
    DAT_004042A6 = 0;
    DAT_004042AA = 0;
    return 0;
}
