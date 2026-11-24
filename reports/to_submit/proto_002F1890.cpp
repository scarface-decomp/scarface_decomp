// bin: proto
// va: 0x002F1890
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1890 (Proto 0x002F1890, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004033DC;
extern "C" int DAT_004033E0;
extern "C" unsigned short DAT_004033E8;
extern "C" unsigned short DAT_004033EA;
extern "C" unsigned short DAT_004033EE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1890(void)
{
    DAT_004033DC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004033E0);
    DAT_004033E0 = 0;
    DAT_004033E8 = 0;
    DAT_004033EA = 0;
    DAT_004033EE = 0;
    return 0;
}
