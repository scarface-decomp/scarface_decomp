// bin: proto
// va: 0x002F61B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F61B0 (Proto 0x002F61B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D548;
extern "C" int DAT_0041D54C;
extern "C" unsigned short DAT_0041D554;
extern "C" unsigned short DAT_0041D556;
extern "C" unsigned short DAT_0041D55A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F61B0(void)
{
    DAT_0041D548 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D54C);
    DAT_0041D54C = 0;
    DAT_0041D554 = 0;
    DAT_0041D556 = 0;
    DAT_0041D55A = 0;
    return 0;
}
