// bin: proto
// va: 0x002F5C10
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5C10 (Proto 0x002F5C10, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419C4C;
extern "C" int DAT_00419C50;
extern "C" unsigned short DAT_00419C58;
extern "C" unsigned short DAT_00419C5A;
extern "C" unsigned short DAT_00419C5E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5C10(void)
{
    DAT_00419C4C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419C50);
    DAT_00419C50 = 0;
    DAT_00419C58 = 0;
    DAT_00419C5A = 0;
    DAT_00419C5E = 0;
    return 0;
}
