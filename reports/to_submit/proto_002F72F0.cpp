// bin: proto
// va: 0x002F72F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F72F0 (Proto 0x002F72F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425750;
extern "C" int DAT_00425754;
extern "C" unsigned short DAT_0042575C;
extern "C" unsigned short DAT_0042575E;
extern "C" unsigned short DAT_00425762;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F72F0(void)
{
    DAT_00425750 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425754);
    DAT_00425754 = 0;
    DAT_0042575C = 0;
    DAT_0042575E = 0;
    DAT_00425762 = 0;
    return 0;
}
