// bin: proto
// va: 0x002F70F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F70F0 (Proto 0x002F70F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0042463C;
extern "C" int DAT_00424640;
extern "C" unsigned short DAT_00424648;
extern "C" unsigned short DAT_0042464A;
extern "C" unsigned short DAT_0042464E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F70F0(void)
{
    DAT_0042463C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00424640);
    DAT_00424640 = 0;
    DAT_00424648 = 0;
    DAT_0042464A = 0;
    DAT_0042464E = 0;
    return 0;
}
