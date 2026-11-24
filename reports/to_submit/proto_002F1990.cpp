// bin: proto
// va: 0x002F1990
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1990 (Proto 0x002F1990, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403B34;
extern "C" int DAT_00403B38;
extern "C" unsigned short DAT_00403B40;
extern "C" unsigned short DAT_00403B42;
extern "C" unsigned short DAT_00403B46;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1990(void)
{
    DAT_00403B34 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403B38);
    DAT_00403B38 = 0;
    DAT_00403B40 = 0;
    DAT_00403B42 = 0;
    DAT_00403B46 = 0;
    return 0;
}
