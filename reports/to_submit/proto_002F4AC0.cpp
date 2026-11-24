// bin: proto
// va: 0x002F4AC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4AC0 (Proto 0x002F4AC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041492C;
extern "C" int DAT_00414930;
extern "C" unsigned short DAT_00414938;
extern "C" unsigned short DAT_0041493A;
extern "C" unsigned short DAT_0041493E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4AC0(void)
{
    DAT_0041492C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00414930);
    DAT_00414930 = 0;
    DAT_00414938 = 0;
    DAT_0041493A = 0;
    DAT_0041493E = 0;
    return 0;
}
