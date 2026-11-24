// bin: proto
// va: 0x002F6270
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6270 (Proto 0x002F6270, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D608;
extern "C" int DAT_0041D60C;
extern "C" unsigned short DAT_0041D614;
extern "C" unsigned short DAT_0041D616;
extern "C" unsigned short DAT_0041D61A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6270(void)
{
    DAT_0041D608 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D60C);
    DAT_0041D60C = 0;
    DAT_0041D614 = 0;
    DAT_0041D616 = 0;
    DAT_0041D61A = 0;
    return 0;
}
