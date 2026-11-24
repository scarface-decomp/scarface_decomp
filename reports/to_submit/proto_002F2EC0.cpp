// bin: proto
// va: 0x002F2EC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2EC0 (Proto 0x002F2EC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040A76C;
extern "C" int DAT_0040A770;
extern "C" unsigned short DAT_0040A778;
extern "C" unsigned short DAT_0040A77A;
extern "C" unsigned short DAT_0040A77E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2EC0(void)
{
    DAT_0040A76C = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040A770);
    DAT_0040A770 = 0;
    DAT_0040A778 = 0;
    DAT_0040A77A = 0;
    DAT_0040A77E = 0;
    return 0;
}
