// bin: proto
// va: 0x002F6B70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6B70 (Proto 0x002F6B70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421378;
extern "C" int DAT_0042137C;
extern "C" unsigned short DAT_00421384;
extern "C" unsigned short DAT_00421386;
extern "C" unsigned short DAT_0042138A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6B70(void)
{
    DAT_00421378 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042137C);
    DAT_0042137C = 0;
    DAT_00421384 = 0;
    DAT_00421386 = 0;
    DAT_0042138A = 0;
    return 0;
}
