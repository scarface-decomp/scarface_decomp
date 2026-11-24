// bin: proto
// va: 0x002F3960
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3960 (Proto 0x002F3960, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041046C;
extern "C" int DAT_00410470;
extern "C" unsigned short DAT_00410478;
extern "C" unsigned short DAT_0041047A;
extern "C" unsigned short DAT_0041047E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3960(void)
{
    DAT_0041046C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410470);
    DAT_00410470 = 0;
    DAT_00410478 = 0;
    DAT_0041047A = 0;
    DAT_0041047E = 0;
    return 0;
}
