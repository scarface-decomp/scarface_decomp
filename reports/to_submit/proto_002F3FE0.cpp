// bin: proto
// va: 0x002F3FE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3FE0 (Proto 0x002F3FE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00411704;
extern "C" int DAT_00411708;
extern "C" unsigned short DAT_00411710;
extern "C" unsigned short DAT_00411712;
extern "C" unsigned short DAT_00411716;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3FE0(void)
{
    DAT_00411704 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411708);
    DAT_00411708 = 0;
    DAT_00411710 = 0;
    DAT_00411712 = 0;
    DAT_00411716 = 0;
    return 0;
}
