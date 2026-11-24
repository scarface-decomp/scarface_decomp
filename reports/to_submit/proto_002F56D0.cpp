// bin: proto
// va: 0x002F56D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F56D0 (Proto 0x002F56D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417F7C;
extern "C" int DAT_00417F80;
extern "C" unsigned short DAT_00417F88;
extern "C" unsigned short DAT_00417F8A;
extern "C" unsigned short DAT_00417F8E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F56D0(void)
{
    DAT_00417F7C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417F80);
    DAT_00417F80 = 0;
    DAT_00417F88 = 0;
    DAT_00417F8A = 0;
    DAT_00417F8E = 0;
    return 0;
}
