// bin: proto
// va: 0x002F6770
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6770 (Proto 0x002F6770, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004210B8;
extern "C" int DAT_004210BC;
extern "C" unsigned short DAT_004210C4;
extern "C" unsigned short DAT_004210C6;
extern "C" unsigned short DAT_004210CA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6770(void)
{
    DAT_004210B8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004210BC);
    DAT_004210BC = 0;
    DAT_004210C4 = 0;
    DAT_004210C6 = 0;
    DAT_004210CA = 0;
    return 0;
}
