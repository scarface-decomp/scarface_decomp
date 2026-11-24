// bin: proto
// va: 0x002F3350
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3350 (Proto 0x002F3350, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040C794;
extern "C" int DAT_0040C798;
extern "C" unsigned short DAT_0040C7A0;
extern "C" unsigned short DAT_0040C7A2;
extern "C" unsigned short DAT_0040C7A6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3350(void)
{
    DAT_0040C794 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040C798);
    DAT_0040C798 = 0;
    DAT_0040C7A0 = 0;
    DAT_0040C7A2 = 0;
    DAT_0040C7A6 = 0;
    return 0;
}
