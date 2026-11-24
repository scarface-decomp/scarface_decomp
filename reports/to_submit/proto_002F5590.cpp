// bin: proto
// va: 0x002F5590
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5590 (Proto 0x002F5590, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417C44;
extern "C" int DAT_00417C48;
extern "C" unsigned short DAT_00417C50;
extern "C" unsigned short DAT_00417C52;
extern "C" unsigned short DAT_00417C56;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5590(void)
{
    DAT_00417C44 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417C48);
    DAT_00417C48 = 0;
    DAT_00417C50 = 0;
    DAT_00417C52 = 0;
    DAT_00417C56 = 0;
    return 0;
}
