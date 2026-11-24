// bin: proto
// va: 0x002F3F20
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3F20 (Proto 0x002F3F20, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004112F8;
extern "C" int DAT_004112FC;
extern "C" unsigned short DAT_00411304;
extern "C" unsigned short DAT_00411306;
extern "C" unsigned short DAT_0041130A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3F20(void)
{
    DAT_004112F8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004112FC);
    DAT_004112FC = 0;
    DAT_00411304 = 0;
    DAT_00411306 = 0;
    DAT_0041130A = 0;
    return 0;
}
