// bin: proto
// va: 0x002F37E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F37E0 (Proto 0x002F37E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041015C;
extern "C" int DAT_00410160;
extern "C" unsigned short DAT_00410168;
extern "C" unsigned short DAT_0041016A;
extern "C" unsigned short DAT_0041016E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F37E0(void)
{
    DAT_0041015C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410160);
    DAT_00410160 = 0;
    DAT_00410168 = 0;
    DAT_0041016A = 0;
    DAT_0041016E = 0;
    return 0;
}
