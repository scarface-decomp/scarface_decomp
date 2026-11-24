// bin: proto
// va: 0x002F6A70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6A70 (Proto 0x002F6A70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004212C8;
extern "C" int DAT_004212CC;
extern "C" unsigned short DAT_004212D4;
extern "C" unsigned short DAT_004212D6;
extern "C" unsigned short DAT_004212DA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6A70(void)
{
    DAT_004212C8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004212CC);
    DAT_004212CC = 0;
    DAT_004212D4 = 0;
    DAT_004212D6 = 0;
    DAT_004212DA = 0;
    return 0;
}
