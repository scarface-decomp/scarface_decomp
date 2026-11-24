// bin: proto
// va: 0x002F2190
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2190 (Proto 0x002F2190, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004040B4;
extern "C" int DAT_004040B8;
extern "C" unsigned short DAT_004040C0;
extern "C" unsigned short DAT_004040C2;
extern "C" unsigned short DAT_004040C6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2190(void)
{
    DAT_004040B4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004040B8);
    DAT_004040B8 = 0;
    DAT_004040C0 = 0;
    DAT_004040C2 = 0;
    DAT_004040C6 = 0;
    return 0;
}
