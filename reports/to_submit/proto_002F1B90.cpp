// bin: proto
// va: 0x002F1B90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1B90 (Proto 0x002F1B90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403C94;
extern "C" int DAT_00403C98;
extern "C" unsigned short DAT_00403CA0;
extern "C" unsigned short DAT_00403CA2;
extern "C" unsigned short DAT_00403CA6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1B90(void)
{
    DAT_00403C94 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403C98);
    DAT_00403C98 = 0;
    DAT_00403CA0 = 0;
    DAT_00403CA2 = 0;
    DAT_00403CA6 = 0;
    return 0;
}
