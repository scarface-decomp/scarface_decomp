// bin: proto
// va: 0x002F2BF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2BF0 (Proto 0x002F2BF0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00409564;
extern "C" int DAT_00409568;
extern "C" unsigned short DAT_00409570;
extern "C" unsigned short DAT_00409572;
extern "C" unsigned short DAT_00409576;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2BF0(void)
{
    DAT_00409564 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00409568);
    DAT_00409568 = 0;
    DAT_00409570 = 0;
    DAT_00409572 = 0;
    DAT_00409576 = 0;
    return 0;
}
