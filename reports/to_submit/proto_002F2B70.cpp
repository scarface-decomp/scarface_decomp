// bin: proto
// va: 0x002F2B70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2B70 (Proto 0x002F2B70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040947C;
extern "C" int DAT_00409480;
extern "C" unsigned short DAT_00409488;
extern "C" unsigned short DAT_0040948A;
extern "C" unsigned short DAT_0040948E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2B70(void)
{
    DAT_0040947C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409480);
    DAT_00409480 = 0;
    DAT_00409488 = 0;
    DAT_0040948A = 0;
    DAT_0040948E = 0;
    return 0;
}
