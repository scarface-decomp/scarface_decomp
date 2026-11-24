// bin: proto
// va: 0x002F43A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F43A0 (Proto 0x002F43A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041229C;
extern "C" int DAT_004122A0;
extern "C" unsigned short DAT_004122A8;
extern "C" unsigned short DAT_004122AA;
extern "C" unsigned short DAT_004122AE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F43A0(void)
{
    DAT_0041229C = (int)DAT_0037CCF4;
    sub_00025160(DAT_004122A0);
    DAT_004122A0 = 0;
    DAT_004122A8 = 0;
    DAT_004122AA = 0;
    DAT_004122AE = 0;
    return 0;
}
