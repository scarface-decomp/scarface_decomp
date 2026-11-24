// bin: proto
// va: 0x002F2310
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2310 (Proto 0x002F2310, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004041BC;
extern "C" int DAT_004041C0;
extern "C" unsigned short DAT_004041C8;
extern "C" unsigned short DAT_004041CA;
extern "C" unsigned short DAT_004041CE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2310(void)
{
    DAT_004041BC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004041C0);
    DAT_004041C0 = 0;
    DAT_004041C8 = 0;
    DAT_004041CA = 0;
    DAT_004041CE = 0;
    return 0;
}
