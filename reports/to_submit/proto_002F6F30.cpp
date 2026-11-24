// bin: proto
// va: 0x002F6F30
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6F30 (Proto 0x002F6F30, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0042166C;
extern "C" int DAT_00421670;
extern "C" unsigned short DAT_00421678;
extern "C" unsigned short DAT_0042167A;
extern "C" unsigned short DAT_0042167E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6F30(void)
{
    DAT_0042166C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421670);
    DAT_00421670 = 0;
    DAT_00421678 = 0;
    DAT_0042167A = 0;
    DAT_0042167E = 0;
    return 0;
}
