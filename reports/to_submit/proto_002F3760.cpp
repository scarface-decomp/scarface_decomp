// bin: proto
// va: 0x002F3760
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3760 (Proto 0x002F3760, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410088;
extern "C" int DAT_0041008C;
extern "C" unsigned short DAT_00410094;
extern "C" unsigned short DAT_00410096;
extern "C" unsigned short DAT_0041009A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3760(void)
{
    DAT_00410088 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041008C);
    DAT_0041008C = 0;
    DAT_00410094 = 0;
    DAT_00410096 = 0;
    DAT_0041009A = 0;
    return 0;
}
