// bin: proto
// va: 0x002F5910
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5910 (Proto 0x002F5910, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00419224;
extern "C" int DAT_00419228;
extern "C" unsigned short DAT_00419230;
extern "C" unsigned short DAT_00419232;
extern "C" unsigned short DAT_00419236;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5910(void)
{
    DAT_00419224 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00419228);
    DAT_00419228 = 0;
    DAT_00419230 = 0;
    DAT_00419232 = 0;
    DAT_00419236 = 0;
    return 0;
}
