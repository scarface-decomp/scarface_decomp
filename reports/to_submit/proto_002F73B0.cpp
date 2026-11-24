// bin: proto
// va: 0x002F73B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F73B0 (Proto 0x002F73B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425A8C;
extern "C" int DAT_00425A90;
extern "C" unsigned short DAT_00425A98;
extern "C" unsigned short DAT_00425A9A;
extern "C" unsigned short DAT_00425A9E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F73B0(void)
{
    DAT_00425A8C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425A90);
    DAT_00425A90 = 0;
    DAT_00425A98 = 0;
    DAT_00425A9A = 0;
    DAT_00425A9E = 0;
    return 0;
}
