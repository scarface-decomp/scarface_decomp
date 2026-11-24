// bin: proto
// va: 0x002F3B60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3B60 (Proto 0x002F3B60, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00410814;
extern "C" int DAT_00410818;
extern "C" unsigned short DAT_00410820;
extern "C" unsigned short DAT_00410822;
extern "C" unsigned short DAT_00410826;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3B60(void)
{
    DAT_00410814 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00410818);
    DAT_00410818 = 0;
    DAT_00410820 = 0;
    DAT_00410822 = 0;
    DAT_00410826 = 0;
    return 0;
}
