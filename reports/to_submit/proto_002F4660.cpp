// bin: proto
// va: 0x002F4660
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4660 (Proto 0x002F4660, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004134B8;
extern "C" int DAT_004134BC;
extern "C" unsigned short DAT_004134C4;
extern "C" unsigned short DAT_004134C6;
extern "C" unsigned short DAT_004134CA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4660(void)
{
    DAT_004134B8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004134BC);
    DAT_004134BC = 0;
    DAT_004134C4 = 0;
    DAT_004134C6 = 0;
    DAT_004134CA = 0;
    return 0;
}
