// bin: proto
// va: 0x002F1500
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1500 (Proto 0x002F1500, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FF214;
extern "C" int DAT_003FF218;
extern "C" unsigned short DAT_003FF220;
extern "C" unsigned short DAT_003FF222;
extern "C" unsigned short DAT_003FF226;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1500(void)
{
    DAT_003FF214 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FF218);
    DAT_003FF218 = 0;
    DAT_003FF220 = 0;
    DAT_003FF222 = 0;
    DAT_003FF226 = 0;
    return 0;
}
