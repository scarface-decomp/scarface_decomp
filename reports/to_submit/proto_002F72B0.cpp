// bin: proto
// va: 0x002F72B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F72B0 (Proto 0x002F72B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425470;
extern "C" int DAT_00425474;
extern "C" unsigned short DAT_0042547C;
extern "C" unsigned short DAT_0042547E;
extern "C" unsigned short DAT_00425482;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F72B0(void)
{
    DAT_00425470 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425474);
    DAT_00425474 = 0;
    DAT_0042547C = 0;
    DAT_0042547E = 0;
    DAT_00425482 = 0;
    return 0;
}
