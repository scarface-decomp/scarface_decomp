// bin: proto
// va: 0x002F63F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F63F0 (Proto 0x002F63F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041DE70;
extern "C" int DAT_0041DE74;
extern "C" unsigned short DAT_0041DE7C;
extern "C" unsigned short DAT_0041DE7E;
extern "C" unsigned short DAT_0041DE82;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F63F0(void)
{
    DAT_0041DE70 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041DE74);
    DAT_0041DE74 = 0;
    DAT_0041DE7C = 0;
    DAT_0041DE7E = 0;
    DAT_0041DE82 = 0;
    return 0;
}
