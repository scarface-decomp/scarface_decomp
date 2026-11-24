// bin: proto
// va: 0x002F5ED0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5ED0 (Proto 0x002F5ED0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041AD6C;
extern "C" int DAT_0041AD70;
extern "C" unsigned short DAT_0041AD78;
extern "C" unsigned short DAT_0041AD7A;
extern "C" unsigned short DAT_0041AD7E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5ED0(void)
{
    DAT_0041AD6C = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041AD70);
    DAT_0041AD70 = 0;
    DAT_0041AD78 = 0;
    DAT_0041AD7A = 0;
    DAT_0041AD7E = 0;
    return 0;
}
