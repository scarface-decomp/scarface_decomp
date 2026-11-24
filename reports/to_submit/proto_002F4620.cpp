// bin: proto
// va: 0x002F4620
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4620 (Proto 0x002F4620, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041348C;
extern "C" int DAT_00413490;
extern "C" unsigned short DAT_00413498;
extern "C" unsigned short DAT_0041349A;
extern "C" unsigned short DAT_0041349E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F4620(void)
{
    DAT_0041348C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00413490);
    DAT_00413490 = 0;
    DAT_00413498 = 0;
    DAT_0041349A = 0;
    DAT_0041349E = 0;
    return 0;
}
