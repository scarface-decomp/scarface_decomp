// bin: proto
// va: 0x002F3BA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3BA0 (Proto 0x002F3BA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410840;
extern "C" int DAT_00410844;
extern "C" unsigned short DAT_0041084C;
extern "C" unsigned short DAT_0041084E;
extern "C" unsigned short DAT_00410852;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3BA0(void)
{
    DAT_00410840 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410844);
    DAT_00410844 = 0;
    DAT_0041084C = 0;
    DAT_0041084E = 0;
    DAT_00410852 = 0;
    return 0;
}
