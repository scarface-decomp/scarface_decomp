// bin: proto
// va: 0x002F65B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F65B0 (Proto 0x002F65B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F608;
extern "C" int DAT_0041F60C;
extern "C" unsigned short DAT_0041F614;
extern "C" unsigned short DAT_0041F616;
extern "C" unsigned short DAT_0041F61A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F65B0(void)
{
    DAT_0041F608 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F60C);
    DAT_0041F60C = 0;
    DAT_0041F614 = 0;
    DAT_0041F616 = 0;
    DAT_0041F61A = 0;
    return 0;
}
