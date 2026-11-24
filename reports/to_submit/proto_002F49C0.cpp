// bin: proto
// va: 0x002F49C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F49C0 (Proto 0x002F49C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004141FC;
extern "C" int DAT_00414200;
extern "C" unsigned short DAT_00414208;
extern "C" unsigned short DAT_0041420A;
extern "C" unsigned short DAT_0041420E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F49C0(void)
{
    DAT_004141FC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00414200);
    DAT_00414200 = 0;
    DAT_00414208 = 0;
    DAT_0041420A = 0;
    DAT_0041420E = 0;
    return 0;
}
