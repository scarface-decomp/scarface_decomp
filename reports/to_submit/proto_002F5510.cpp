// bin: proto
// va: 0x002F5510
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5510 (Proto 0x002F5510, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417954;
extern "C" int DAT_00417958;
extern "C" unsigned short DAT_00417960;
extern "C" unsigned short DAT_00417962;
extern "C" unsigned short DAT_00417966;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5510(void)
{
    DAT_00417954 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417958);
    DAT_00417958 = 0;
    DAT_00417960 = 0;
    DAT_00417962 = 0;
    DAT_00417966 = 0;
    return 0;
}
