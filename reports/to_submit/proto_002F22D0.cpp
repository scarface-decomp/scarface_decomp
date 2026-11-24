// bin: proto
// va: 0x002F22D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F22D0 (Proto 0x002F22D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404190;
extern "C" int DAT_00404194;
extern "C" unsigned short DAT_0040419C;
extern "C" unsigned short DAT_0040419E;
extern "C" unsigned short DAT_004041A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F22D0(void)
{
    DAT_00404190 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404194);
    DAT_00404194 = 0;
    DAT_0040419C = 0;
    DAT_0040419E = 0;
    DAT_004041A2 = 0;
    return 0;
}
