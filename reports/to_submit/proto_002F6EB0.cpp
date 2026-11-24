// bin: proto
// va: 0x002F6EB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6EB0 (Proto 0x002F6EB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421614;
extern "C" int DAT_00421618;
extern "C" unsigned short DAT_00421620;
extern "C" unsigned short DAT_00421622;
extern "C" unsigned short DAT_00421626;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6EB0(void)
{
    DAT_00421614 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421618);
    DAT_00421618 = 0;
    DAT_00421620 = 0;
    DAT_00421622 = 0;
    DAT_00421626 = 0;
    return 0;
}
