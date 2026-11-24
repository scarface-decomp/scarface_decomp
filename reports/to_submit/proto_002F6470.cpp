// bin: proto
// va: 0x002F6470
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6470 (Proto 0x002F6470, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041DF54;
extern "C" int DAT_0041DF58;
extern "C" unsigned short DAT_0041DF60;
extern "C" unsigned short DAT_0041DF62;
extern "C" unsigned short DAT_0041DF66;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6470(void)
{
    DAT_0041DF54 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041DF58);
    DAT_0041DF58 = 0;
    DAT_0041DF60 = 0;
    DAT_0041DF62 = 0;
    DAT_0041DF66 = 0;
    return 0;
}
