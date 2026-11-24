// bin: proto
// va: 0x002F6EF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6EF0 (Proto 0x002F6EF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421640;
extern "C" int DAT_00421644;
extern "C" unsigned short DAT_0042164C;
extern "C" unsigned short DAT_0042164E;
extern "C" unsigned short DAT_00421652;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6EF0(void)
{
    DAT_00421640 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421644);
    DAT_00421644 = 0;
    DAT_0042164C = 0;
    DAT_0042164E = 0;
    DAT_00421652 = 0;
    return 0;
}
