// bin: proto
// va: 0x002F2210
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2210 (Proto 0x002F2210, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040410C;
extern "C" int DAT_00404110;
extern "C" unsigned short DAT_00404118;
extern "C" unsigned short DAT_0040411A;
extern "C" unsigned short DAT_0040411E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2210(void)
{
    DAT_0040410C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404110);
    DAT_00404110 = 0;
    DAT_00404118 = 0;
    DAT_0040411A = 0;
    DAT_0040411E = 0;
    return 0;
}
