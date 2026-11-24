// bin: proto
// va: 0x002F2A70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2A70 (Proto 0x002F2A70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409390;
extern "C" int DAT_00409394;
extern "C" unsigned short DAT_0040939C;
extern "C" unsigned short DAT_0040939E;
extern "C" unsigned short DAT_004093A2;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2A70(void)
{
    DAT_00409390 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409394);
    DAT_00409394 = 0;
    DAT_0040939C = 0;
    DAT_0040939E = 0;
    DAT_004093A2 = 0;
    return 0;
}
