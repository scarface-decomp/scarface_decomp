// bin: proto
// va: 0x002F4F80
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4F80 (Proto 0x002F4F80, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417188;
extern "C" int DAT_0041718C;
extern "C" unsigned short DAT_00417194;
extern "C" unsigned short DAT_00417196;
extern "C" unsigned short DAT_0041719A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4F80(void)
{
    DAT_00417188 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041718C);
    DAT_0041718C = 0;
    DAT_00417194 = 0;
    DAT_00417196 = 0;
    DAT_0041719A = 0;
    return 0;
}
