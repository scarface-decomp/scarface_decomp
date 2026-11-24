// bin: proto
// va: 0x002F6C30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6C30 (Proto 0x002F6C30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421454;
extern "C" int DAT_00421458;
extern "C" unsigned short DAT_00421460;
extern "C" unsigned short DAT_00421462;
extern "C" unsigned short DAT_00421466;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6C30(void)
{
    DAT_00421454 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421458);
    DAT_00421458 = 0;
    DAT_00421460 = 0;
    DAT_00421462 = 0;
    DAT_00421466 = 0;
    return 0;
}
