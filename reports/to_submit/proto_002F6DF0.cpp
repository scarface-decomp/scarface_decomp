// bin: proto
// va: 0x002F6DF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6DF0 (Proto 0x002F6DF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421590;
extern "C" int DAT_00421594;
extern "C" unsigned short DAT_0042159C;
extern "C" unsigned short DAT_0042159E;
extern "C" unsigned short DAT_004215A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6DF0(void)
{
    DAT_00421590 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421594);
    DAT_00421594 = 0;
    DAT_0042159C = 0;
    DAT_0042159E = 0;
    DAT_004215A2 = 0;
    return 0;
}
