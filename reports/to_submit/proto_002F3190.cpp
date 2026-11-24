// bin: proto
// va: 0x002F3190
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3190 (Proto 0x002F3190, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0040AEE8;
extern "C" int DAT_0040AEEC;
extern "C" unsigned short DAT_0040AEF4;
extern "C" unsigned short DAT_0040AEF6;
extern "C" unsigned short DAT_0040AEFA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3190(void)
{
    DAT_0040AEE8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0040AEEC);
    DAT_0040AEEC = 0;
    DAT_0040AEF4 = 0;
    DAT_0040AEF6 = 0;
    DAT_0040AEFA = 0;
    return 0;
}
