// bin: proto
// va: 0x002F6670
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6670 (Proto 0x002F6670, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F68C;
extern "C" int DAT_0041F690;
extern "C" unsigned short DAT_0041F698;
extern "C" unsigned short DAT_0041F69A;
extern "C" unsigned short DAT_0041F69E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6670(void)
{
    DAT_0041F68C = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F690);
    DAT_0041F690 = 0;
    DAT_0041F698 = 0;
    DAT_0041F69A = 0;
    DAT_0041F69E = 0;
    return 0;
}
