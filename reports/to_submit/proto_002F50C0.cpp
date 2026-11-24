// bin: proto
// va: 0x002F50C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F50C0 (Proto 0x002F50C0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417264;
extern "C" int DAT_00417268;
extern "C" unsigned short DAT_00417270;
extern "C" unsigned short DAT_00417272;
extern "C" unsigned short DAT_00417276;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F50C0(void)
{
    DAT_00417264 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417268);
    DAT_00417268 = 0;
    DAT_00417270 = 0;
    DAT_00417272 = 0;
    DAT_00417276 = 0;
    return 0;
}
