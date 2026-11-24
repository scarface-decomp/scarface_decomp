// bin: proto
// va: 0x002F62B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F62B0 (Proto 0x002F62B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D8E0;
extern "C" int DAT_0041D8E4;
extern "C" unsigned short DAT_0041D8EC;
extern "C" unsigned short DAT_0041D8EE;
extern "C" unsigned short DAT_0041D8F2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F62B0(void)
{
    DAT_0041D8E0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D8E4);
    DAT_0041D8E4 = 0;
    DAT_0041D8EC = 0;
    DAT_0041D8EE = 0;
    DAT_0041D8F2 = 0;
    return 0;
}
