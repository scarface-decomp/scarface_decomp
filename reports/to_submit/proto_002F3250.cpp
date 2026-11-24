// bin: proto
// va: 0x002F3250
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3250 (Proto 0x002F3250, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040BAA8;
extern "C" int DAT_0040BAAC;
extern "C" unsigned short DAT_0040BAB4;
extern "C" unsigned short DAT_0040BAB6;
extern "C" unsigned short DAT_0040BABA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3250(void)
{
    DAT_0040BAA8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040BAAC);
    DAT_0040BAAC = 0;
    DAT_0040BAB4 = 0;
    DAT_0040BAB6 = 0;
    DAT_0040BABA = 0;
    return 0;
}
