// bin: proto
// va: 0x002F2840
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2840 (Proto 0x002F2840, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00408884;
extern "C" int DAT_00408888;
extern "C" unsigned short DAT_00408890;
extern "C" unsigned short DAT_00408892;
extern "C" unsigned short DAT_00408896;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2840(void)
{
    DAT_00408884 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00408888);
    DAT_00408888 = 0;
    DAT_00408890 = 0;
    DAT_00408892 = 0;
    DAT_00408896 = 0;
    return 0;
}
