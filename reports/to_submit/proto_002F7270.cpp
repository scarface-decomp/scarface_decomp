// bin: proto
// va: 0x002F7270
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7270 (Proto 0x002F7270, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0042543C;
extern "C" int DAT_00425440;
extern "C" unsigned short DAT_00425448;
extern "C" unsigned short DAT_0042544A;
extern "C" unsigned short DAT_0042544E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7270(void)
{
    DAT_0042543C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425440);
    DAT_00425440 = 0;
    DAT_00425448 = 0;
    DAT_0042544A = 0;
    DAT_0042544E = 0;
    return 0;
}
