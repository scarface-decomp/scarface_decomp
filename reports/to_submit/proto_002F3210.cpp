// bin: proto
// va: 0x002F3210
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3210 (Proto 0x002F3210, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040B040;
extern "C" int DAT_0040B044;
extern "C" unsigned short DAT_0040B04C;
extern "C" unsigned short DAT_0040B04E;
extern "C" unsigned short DAT_0040B052;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3210(void)
{
    DAT_0040B040 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040B044);
    DAT_0040B044 = 0;
    DAT_0040B04C = 0;
    DAT_0040B04E = 0;
    DAT_0040B052 = 0;
    return 0;
}
