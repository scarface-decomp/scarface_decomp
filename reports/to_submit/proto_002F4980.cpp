// bin: proto
// va: 0x002F4980
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4980 (Proto 0x002F4980, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00413FB4;
extern "C" int DAT_00413FB8;
extern "C" unsigned short DAT_00413FC0;
extern "C" unsigned short DAT_00413FC2;
extern "C" unsigned short DAT_00413FC6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4980(void)
{
    DAT_00413FB4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413FB8);
    DAT_00413FB8 = 0;
    DAT_00413FC0 = 0;
    DAT_00413FC2 = 0;
    DAT_00413FC6 = 0;
    return 0;
}
