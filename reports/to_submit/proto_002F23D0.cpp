// bin: proto
// va: 0x002F23D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F23D0 (Proto 0x002F23D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00404240;
extern "C" int DAT_00404244;
extern "C" unsigned short DAT_0040424C;
extern "C" unsigned short DAT_0040424E;
extern "C" unsigned short DAT_00404252;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F23D0(void)
{
    DAT_00404240 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00404244);
    DAT_00404244 = 0;
    DAT_0040424C = 0;
    DAT_0040424E = 0;
    DAT_00404252 = 0;
    return 0;
}
