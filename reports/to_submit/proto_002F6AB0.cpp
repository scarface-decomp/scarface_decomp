// bin: proto
// va: 0x002F6AB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6AB0 (Proto 0x002F6AB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004212F4;
extern "C" int DAT_004212F8;
extern "C" unsigned short DAT_00421300;
extern "C" unsigned short DAT_00421302;
extern "C" unsigned short DAT_00421306;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6AB0(void)
{
    DAT_004212F4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004212F8);
    DAT_004212F8 = 0;
    DAT_00421300 = 0;
    DAT_00421302 = 0;
    DAT_00421306 = 0;
    return 0;
}
