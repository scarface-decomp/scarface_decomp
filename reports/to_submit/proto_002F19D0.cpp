// bin: proto
// va: 0x002F19D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F19D0 (Proto 0x002F19D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403B60;
extern "C" int DAT_00403B64;
extern "C" unsigned short DAT_00403B6C;
extern "C" unsigned short DAT_00403B6E;
extern "C" unsigned short DAT_00403B72;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F19D0(void)
{
    DAT_00403B60 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403B64);
    DAT_00403B64 = 0;
    DAT_00403B6C = 0;
    DAT_00403B6E = 0;
    DAT_00403B72 = 0;
    return 0;
}
