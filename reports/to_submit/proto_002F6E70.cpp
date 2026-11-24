// bin: proto
// va: 0x002F6E70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6E70 (Proto 0x002F6E70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004215E8;
extern "C" int DAT_004215EC;
extern "C" unsigned short DAT_004215F4;
extern "C" unsigned short DAT_004215F6;
extern "C" unsigned short DAT_004215FA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6E70(void)
{
    DAT_004215E8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004215EC);
    DAT_004215EC = 0;
    DAT_004215F4 = 0;
    DAT_004215F6 = 0;
    DAT_004215FA = 0;
    return 0;
}
