// bin: proto
// va: 0x002F5B50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5B50 (Proto 0x002F5B50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004199E8;
extern "C" int DAT_004199EC;
extern "C" unsigned short DAT_004199F4;
extern "C" unsigned short DAT_004199F6;
extern "C" unsigned short DAT_004199FA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5B50(void)
{
    DAT_004199E8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004199EC);
    DAT_004199EC = 0;
    DAT_004199F4 = 0;
    DAT_004199F6 = 0;
    DAT_004199FA = 0;
    return 0;
}
