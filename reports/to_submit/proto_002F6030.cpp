// bin: proto
// va: 0x002F6030
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6030 (Proto 0x002F6030, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041BA94;
extern "C" int DAT_0041BA98;
extern "C" unsigned short DAT_0041BAA0;
extern "C" unsigned short DAT_0041BAA2;
extern "C" unsigned short DAT_0041BAA6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6030(void)
{
    DAT_0041BA94 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041BA98);
    DAT_0041BA98 = 0;
    DAT_0041BAA0 = 0;
    DAT_0041BAA2 = 0;
    DAT_0041BAA6 = 0;
    return 0;
}
