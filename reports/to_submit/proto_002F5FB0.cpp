// bin: proto
// va: 0x002F5FB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5FB0 (Proto 0x002F5FB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041B958;
extern "C" int DAT_0041B95C;
extern "C" unsigned short DAT_0041B964;
extern "C" unsigned short DAT_0041B966;
extern "C" unsigned short DAT_0041B96A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5FB0(void)
{
    DAT_0041B958 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041B95C);
    DAT_0041B95C = 0;
    DAT_0041B964 = 0;
    DAT_0041B966 = 0;
    DAT_0041B96A = 0;
    return 0;
}
