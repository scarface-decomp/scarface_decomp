// bin: proto
// va: 0x002F6B30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6B30 (Proto 0x002F6B30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0042134C;
extern "C" int DAT_00421350;
extern "C" unsigned short DAT_00421358;
extern "C" unsigned short DAT_0042135A;
extern "C" unsigned short DAT_0042135E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6B30(void)
{
    DAT_0042134C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421350);
    DAT_00421350 = 0;
    DAT_00421358 = 0;
    DAT_0042135A = 0;
    DAT_0042135E = 0;
    return 0;
}
