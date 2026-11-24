// bin: proto
// va: 0x002F6130
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6130 (Proto 0x002F6130, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041BE14;
extern "C" int DAT_0041BE18;
extern "C" unsigned short DAT_0041BE20;
extern "C" unsigned short DAT_0041BE22;
extern "C" unsigned short DAT_0041BE26;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6130(void)
{
    DAT_0041BE14 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041BE18);
    DAT_0041BE18 = 0;
    DAT_0041BE20 = 0;
    DAT_0041BE22 = 0;
    DAT_0041BE26 = 0;
    return 0;
}
