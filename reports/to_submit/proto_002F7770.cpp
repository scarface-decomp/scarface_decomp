// bin: proto
// va: 0x002F7770
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7770 (Proto 0x002F7770, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00427280;
extern "C" int DAT_00427284;
extern "C" unsigned short DAT_0042728C;
extern "C" unsigned short DAT_0042728E;
extern "C" unsigned short DAT_00427292;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7770(void)
{
    DAT_00427280 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00427284);
    DAT_00427284 = 0;
    DAT_0042728C = 0;
    DAT_0042728E = 0;
    DAT_00427292 = 0;
    return 0;
}
