// bin: proto
// va: 0x002F1A50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1A50 (Proto 0x002F1A50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403BB8;
extern "C" int DAT_00403BBC;
extern "C" unsigned short DAT_00403BC4;
extern "C" unsigned short DAT_00403BC6;
extern "C" unsigned short DAT_00403BCA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1A50(void)
{
    DAT_00403BB8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403BBC);
    DAT_00403BBC = 0;
    DAT_00403BC4 = 0;
    DAT_00403BC6 = 0;
    DAT_00403BCA = 0;
    return 0;
}
