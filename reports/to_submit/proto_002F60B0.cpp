// bin: proto
// va: 0x002F60B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F60B0 (Proto 0x002F60B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041BD94;
extern "C" int DAT_0041BD98;
extern "C" unsigned short DAT_0041BDA0;
extern "C" unsigned short DAT_0041BDA2;
extern "C" unsigned short DAT_0041BDA6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F60B0(void)
{
    DAT_0041BD94 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041BD98);
    DAT_0041BD98 = 0;
    DAT_0041BDA0 = 0;
    DAT_0041BDA2 = 0;
    DAT_0041BDA6 = 0;
    return 0;
}
