// bin: proto
// va: 0x002F51C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F51C0 (Proto 0x002F51C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417314;
extern "C" int DAT_00417318;
extern "C" unsigned short DAT_00417320;
extern "C" unsigned short DAT_00417322;
extern "C" unsigned short DAT_00417326;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F51C0(void)
{
    DAT_00417314 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417318);
    DAT_00417318 = 0;
    DAT_00417320 = 0;
    DAT_00417322 = 0;
    DAT_00417326 = 0;
    return 0;
}
