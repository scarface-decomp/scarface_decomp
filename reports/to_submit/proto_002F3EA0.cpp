// bin: proto
// va: 0x002F3EA0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3EA0 (Proto 0x002F3EA0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411028;
extern "C" int DAT_0041102C;
extern "C" unsigned short DAT_00411034;
extern "C" unsigned short DAT_00411036;
extern "C" unsigned short DAT_0041103A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3EA0(void)
{
    DAT_00411028 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041102C);
    DAT_0041102C = 0;
    DAT_00411034 = 0;
    DAT_00411036 = 0;
    DAT_0041103A = 0;
    return 0;
}
