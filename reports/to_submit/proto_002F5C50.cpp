// bin: proto
// va: 0x002F5C50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5C50 (Proto 0x002F5C50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419CE0;
extern "C" int DAT_00419CE4;
extern "C" unsigned short DAT_00419CEC;
extern "C" unsigned short DAT_00419CEE;
extern "C" unsigned short DAT_00419CF2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5C50(void)
{
    DAT_00419CE0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419CE4);
    DAT_00419CE4 = 0;
    DAT_00419CEC = 0;
    DAT_00419CEE = 0;
    DAT_00419CF2 = 0;
    return 0;
}
