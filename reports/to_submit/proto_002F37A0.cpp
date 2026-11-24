// bin: proto
// va: 0x002F37A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F37A0 (Proto 0x002F37A0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004100F8;
extern "C" int DAT_004100FC;
extern "C" unsigned short DAT_00410104;
extern "C" unsigned short DAT_00410106;
extern "C" unsigned short DAT_0041010A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F37A0(void)
{
    DAT_004100F8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004100FC);
    DAT_004100FC = 0;
    DAT_00410104 = 0;
    DAT_00410106 = 0;
    DAT_0041010A = 0;
    return 0;
}
