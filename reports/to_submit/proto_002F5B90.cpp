// bin: proto
// va: 0x002F5B90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5B90 (Proto 0x002F5B90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419A60;
extern "C" int DAT_00419A64;
extern "C" unsigned short DAT_00419A6C;
extern "C" unsigned short DAT_00419A6E;
extern "C" unsigned short DAT_00419A72;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5B90(void)
{
    DAT_00419A60 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419A64);
    DAT_00419A64 = 0;
    DAT_00419A6C = 0;
    DAT_00419A6E = 0;
    DAT_00419A72 = 0;
    return 0;
}
