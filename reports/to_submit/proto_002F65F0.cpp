// bin: proto
// va: 0x002F65F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F65F0 (Proto 0x002F65F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F634;
extern "C" int DAT_0041F638;
extern "C" unsigned short DAT_0041F640;
extern "C" unsigned short DAT_0041F642;
extern "C" unsigned short DAT_0041F646;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F65F0(void)
{
    DAT_0041F634 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F638);
    DAT_0041F638 = 0;
    DAT_0041F640 = 0;
    DAT_0041F642 = 0;
    DAT_0041F646 = 0;
    return 0;
}
