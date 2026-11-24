// bin: proto
// va: 0x002F5080
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5080 (Proto 0x002F5080, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417238;
extern "C" int DAT_0041723C;
extern "C" unsigned short DAT_00417244;
extern "C" unsigned short DAT_00417246;
extern "C" unsigned short DAT_0041724A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5080(void)
{
    DAT_00417238 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041723C);
    DAT_0041723C = 0;
    DAT_00417244 = 0;
    DAT_00417246 = 0;
    DAT_0041724A = 0;
    return 0;
}
