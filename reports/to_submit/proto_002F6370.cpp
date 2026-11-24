// bin: proto
// va: 0x002F6370
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6370 (Proto 0x002F6370, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041DE18;
extern "C" int DAT_0041DE1C;
extern "C" unsigned short DAT_0041DE24;
extern "C" unsigned short DAT_0041DE26;
extern "C" unsigned short DAT_0041DE2A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6370(void)
{
    DAT_0041DE18 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041DE1C);
    DAT_0041DE1C = 0;
    DAT_0041DE24 = 0;
    DAT_0041DE26 = 0;
    DAT_0041DE2A = 0;
    return 0;
}
