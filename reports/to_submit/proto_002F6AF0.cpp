// bin: proto
// va: 0x002F6AF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6AF0 (Proto 0x002F6AF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421320;
extern "C" int DAT_00421324;
extern "C" unsigned short DAT_0042132C;
extern "C" unsigned short DAT_0042132E;
extern "C" unsigned short DAT_00421332;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6AF0(void)
{
    DAT_00421320 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421324);
    DAT_00421324 = 0;
    DAT_0042132C = 0;
    DAT_0042132E = 0;
    DAT_00421332 = 0;
    return 0;
}
