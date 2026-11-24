// bin: proto
// va: 0x002F6330
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6330 (Proto 0x002F6330, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D9B0;
extern "C" int DAT_0041D9B4;
extern "C" unsigned short DAT_0041D9BC;
extern "C" unsigned short DAT_0041D9BE;
extern "C" unsigned short DAT_0041D9C2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6330(void)
{
    DAT_0041D9B0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D9B4);
    DAT_0041D9B4 = 0;
    DAT_0041D9BC = 0;
    DAT_0041D9BE = 0;
    DAT_0041D9C2 = 0;
    return 0;
}
