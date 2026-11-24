// bin: proto
// va: 0x002F5BD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5BD0 (Proto 0x002F5BD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419BBC;
extern "C" int DAT_00419BC0;
extern "C" unsigned short DAT_00419BC8;
extern "C" unsigned short DAT_00419BCA;
extern "C" unsigned short DAT_00419BCE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5BD0(void)
{
    DAT_00419BBC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419BC0);
    DAT_00419BC0 = 0;
    DAT_00419BC8 = 0;
    DAT_00419BCA = 0;
    DAT_00419BCE = 0;
    return 0;
}
