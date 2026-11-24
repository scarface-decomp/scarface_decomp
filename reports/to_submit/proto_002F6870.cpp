// bin: proto
// va: 0x002F6870
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6870 (Proto 0x002F6870, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421168;
extern "C" int DAT_0042116C;
extern "C" unsigned short DAT_00421174;
extern "C" unsigned short DAT_00421176;
extern "C" unsigned short DAT_0042117A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6870(void)
{
    DAT_00421168 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042116C);
    DAT_0042116C = 0;
    DAT_00421174 = 0;
    DAT_00421176 = 0;
    DAT_0042117A = 0;
    return 0;
}
