// bin: proto
// va: 0x002F66F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F66F0 (Proto 0x002F66F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F6E4;
extern "C" int DAT_0041F6E8;
extern "C" unsigned short DAT_0041F6F0;
extern "C" unsigned short DAT_0041F6F2;
extern "C" unsigned short DAT_0041F6F6;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F66F0(void)
{
    DAT_0041F6E4 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F6E8);
    DAT_0041F6E8 = 0;
    DAT_0041F6F0 = 0;
    DAT_0041F6F2 = 0;
    DAT_0041F6F6 = 0;
    return 0;
}
