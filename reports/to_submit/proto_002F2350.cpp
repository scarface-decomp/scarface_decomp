// bin: proto
// va: 0x002F2350
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2350 (Proto 0x002F2350, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004041E8;
extern "C" int DAT_004041EC;
extern "C" unsigned short DAT_004041F4;
extern "C" unsigned short DAT_004041F6;
extern "C" unsigned short DAT_004041FA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F2350(void)
{
    DAT_004041E8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004041EC);
    DAT_004041EC = 0;
    DAT_004041F4 = 0;
    DAT_004041F6 = 0;
    DAT_004041FA = 0;
    return 0;
}
