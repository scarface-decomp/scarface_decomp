// bin: proto
// va: 0x002F2970
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2970 (Proto 0x002F2970, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409070;
extern "C" int DAT_00409074;
extern "C" unsigned short DAT_0040907C;
extern "C" unsigned short DAT_0040907E;
extern "C" unsigned short DAT_00409082;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2970(void)
{
    DAT_00409070 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409074);
    DAT_00409074 = 0;
    DAT_0040907C = 0;
    DAT_0040907E = 0;
    DAT_00409082 = 0;
    return 0;
}
