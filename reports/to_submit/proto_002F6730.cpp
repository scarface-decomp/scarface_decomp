// bin: proto
// va: 0x002F6730
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6730 (Proto 0x002F6730, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F710;
extern "C" int DAT_0041F714;
extern "C" unsigned short DAT_0041F71C;
extern "C" unsigned short DAT_0041F71E;
extern "C" unsigned short DAT_0041F722;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6730(void)
{
    DAT_0041F710 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F714);
    DAT_0041F714 = 0;
    DAT_0041F71C = 0;
    DAT_0041F71E = 0;
    DAT_0041F722 = 0;
    return 0;
}
