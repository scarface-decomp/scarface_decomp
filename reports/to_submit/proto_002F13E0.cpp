// bin: proto
// va: 0x002F13E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F13E0 (Proto 0x002F13E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FE1F0;
extern "C" int DAT_003FE1F4;
extern "C" unsigned short DAT_003FE1FC;
extern "C" unsigned short DAT_003FE1FE;
extern "C" unsigned short DAT_003FE202;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F13E0(void)
{
    DAT_003FE1F0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FE1F4);
    DAT_003FE1F4 = 0;
    DAT_003FE1FC = 0;
    DAT_003FE1FE = 0;
    DAT_003FE202 = 0;
    return 0;
}
