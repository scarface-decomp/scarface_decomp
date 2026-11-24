// bin: proto
// va: 0x002F5040
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5040 (Proto 0x002F5040, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041720C;
extern "C" int DAT_00417210;
extern "C" unsigned short DAT_00417218;
extern "C" unsigned short DAT_0041721A;
extern "C" unsigned short DAT_0041721E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5040(void)
{
    DAT_0041720C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417210);
    DAT_00417210 = 0;
    DAT_00417218 = 0;
    DAT_0041721A = 0;
    DAT_0041721E = 0;
    return 0;
}
