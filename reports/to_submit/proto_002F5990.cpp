// bin: proto
// va: 0x002F5990
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5990 (Proto 0x002F5990, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041927C;
extern "C" int DAT_00419280;
extern "C" unsigned short DAT_00419288;
extern "C" unsigned short DAT_0041928A;
extern "C" unsigned short DAT_0041928E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5990(void)
{
    DAT_0041927C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419280);
    DAT_00419280 = 0;
    DAT_00419288 = 0;
    DAT_0041928A = 0;
    DAT_0041928E = 0;
    return 0;
}
