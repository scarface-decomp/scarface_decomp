// bin: proto
// va: 0x002F4120
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4120 (Proto 0x002F4120, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004119DC;
extern "C" int DAT_004119E0;
extern "C" unsigned short DAT_004119E8;
extern "C" unsigned short DAT_004119EA;
extern "C" unsigned short DAT_004119EE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4120(void)
{
    DAT_004119DC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004119E0);
    DAT_004119E0 = 0;
    DAT_004119E8 = 0;
    DAT_004119EA = 0;
    DAT_004119EE = 0;
    return 0;
}
