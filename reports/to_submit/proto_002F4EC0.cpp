// bin: proto
// va: 0x002F4EC0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4EC0 (Proto 0x002F4EC0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00417104;
extern "C" int DAT_00417108;
extern "C" unsigned short DAT_00417110;
extern "C" unsigned short DAT_00417112;
extern "C" unsigned short DAT_00417116;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4EC0(void)
{
    DAT_00417104 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00417108);
    DAT_00417108 = 0;
    DAT_00417110 = 0;
    DAT_00417112 = 0;
    DAT_00417116 = 0;
    return 0;
}
