// bin: proto
// va: 0x002F3490
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3490 (Proto 0x002F3490, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040C8CC;
extern "C" int DAT_0040C8D0;
extern "C" unsigned short DAT_0040C8D8;
extern "C" unsigned short DAT_0040C8DA;
extern "C" unsigned short DAT_0040C8DE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3490(void)
{
    DAT_0040C8CC = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040C8D0);
    DAT_0040C8D0 = 0;
    DAT_0040C8D8 = 0;
    DAT_0040C8DA = 0;
    DAT_0040C8DE = 0;
    return 0;
}
