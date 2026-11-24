// bin: proto
// va: 0x002F34D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F34D0 (Proto 0x002F34D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040CAE8;
extern "C" int DAT_0040CAEC;
extern "C" unsigned short DAT_0040CAF4;
extern "C" unsigned short DAT_0040CAF6;
extern "C" unsigned short DAT_0040CAFA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F34D0(void)
{
    DAT_0040CAE8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040CAEC);
    DAT_0040CAEC = 0;
    DAT_0040CAF4 = 0;
    DAT_0040CAF6 = 0;
    DAT_0040CAFA = 0;
    return 0;
}
