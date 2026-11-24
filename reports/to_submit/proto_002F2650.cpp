// bin: proto
// va: 0x002F2650
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2650 (Proto 0x002F2650, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004043F8;
extern "C" int DAT_004043FC;
extern "C" unsigned short DAT_00404404;
extern "C" unsigned short DAT_00404406;
extern "C" unsigned short DAT_0040440A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2650(void)
{
    DAT_004043F8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004043FC);
    DAT_004043FC = 0;
    DAT_00404404 = 0;
    DAT_00404406 = 0;
    DAT_0040440A = 0;
    return 0;
}
