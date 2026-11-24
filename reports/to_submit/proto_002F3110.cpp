// bin: proto
// va: 0x002F3110
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3110 (Proto 0x002F3110, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040ADD0;
extern "C" int DAT_0040ADD4;
extern "C" unsigned short DAT_0040ADDC;
extern "C" unsigned short DAT_0040ADDE;
extern "C" unsigned short DAT_0040ADE2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3110(void)
{
    DAT_0040ADD0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040ADD4);
    DAT_0040ADD4 = 0;
    DAT_0040ADDC = 0;
    DAT_0040ADDE = 0;
    DAT_0040ADE2 = 0;
    return 0;
}
