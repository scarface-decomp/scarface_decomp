// bin: proto
// va: 0x002F4A80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4A80 (Proto 0x002F4A80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00414858;
extern "C" int DAT_0041485C;
extern "C" unsigned short DAT_00414864;
extern "C" unsigned short DAT_00414866;
extern "C" unsigned short DAT_0041486A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4A80(void)
{
    DAT_00414858 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041485C);
    DAT_0041485C = 0;
    DAT_00414864 = 0;
    DAT_00414866 = 0;
    DAT_0041486A = 0;
    return 0;
}
