// bin: proto
// va: 0x002F6630
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6630 (Proto 0x002F6630, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041F660;
extern "C" int DAT_0041F664;
extern "C" unsigned short DAT_0041F66C;
extern "C" unsigned short DAT_0041F66E;
extern "C" unsigned short DAT_0041F672;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6630(void)
{
    DAT_0041F660 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041F664);
    DAT_0041F664 = 0;
    DAT_0041F66C = 0;
    DAT_0041F66E = 0;
    DAT_0041F672 = 0;
    return 0;
}
