// bin: proto
// va: 0x002F2930
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2930 (Proto 0x002F2930, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409044;
extern "C" int DAT_00409048;
extern "C" unsigned short DAT_00409050;
extern "C" unsigned short DAT_00409052;
extern "C" unsigned short DAT_00409056;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2930(void)
{
    DAT_00409044 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409048);
    DAT_00409048 = 0;
    DAT_00409050 = 0;
    DAT_00409052 = 0;
    DAT_00409056 = 0;
    return 0;
}
