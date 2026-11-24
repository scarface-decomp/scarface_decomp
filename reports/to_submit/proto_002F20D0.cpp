// bin: proto
// va: 0x002F20D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F20D0 (Proto 0x002F20D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404030;
extern "C" int DAT_00404034;
extern "C" unsigned short DAT_0040403C;
extern "C" unsigned short DAT_0040403E;
extern "C" unsigned short DAT_00404042;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F20D0(void)
{
    DAT_00404030 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404034);
    DAT_00404034 = 0;
    DAT_0040403C = 0;
    DAT_0040403E = 0;
    DAT_00404042 = 0;
    return 0;
}
