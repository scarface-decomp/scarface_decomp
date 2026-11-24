// bin: proto
// va: 0x002F5280
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5280 (Proto 0x002F5280, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417398;
extern "C" int DAT_0041739C;
extern "C" unsigned short DAT_004173A4;
extern "C" unsigned short DAT_004173A6;
extern "C" unsigned short DAT_004173AA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5280(void)
{
    DAT_00417398 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041739C);
    DAT_0041739C = 0;
    DAT_004173A4 = 0;
    DAT_004173A6 = 0;
    DAT_004173AA = 0;
    return 0;
}
