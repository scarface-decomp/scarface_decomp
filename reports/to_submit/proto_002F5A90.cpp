// bin: proto
// va: 0x002F5A90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5A90 (Proto 0x002F5A90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419830;
extern "C" int DAT_00419834;
extern "C" unsigned short DAT_0041983C;
extern "C" unsigned short DAT_0041983E;
extern "C" unsigned short DAT_00419842;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5A90(void)
{
    DAT_00419830 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419834);
    DAT_00419834 = 0;
    DAT_0041983C = 0;
    DAT_0041983E = 0;
    DAT_00419842 = 0;
    return 0;
}
