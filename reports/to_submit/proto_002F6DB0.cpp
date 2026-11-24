// bin: proto
// va: 0x002F6DB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6DB0 (Proto 0x002F6DB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421564;
extern "C" int DAT_00421568;
extern "C" unsigned short DAT_00421570;
extern "C" unsigned short DAT_00421572;
extern "C" unsigned short DAT_00421576;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6DB0(void)
{
    DAT_00421564 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421568);
    DAT_00421568 = 0;
    DAT_00421570 = 0;
    DAT_00421572 = 0;
    DAT_00421576 = 0;
    return 0;
}
