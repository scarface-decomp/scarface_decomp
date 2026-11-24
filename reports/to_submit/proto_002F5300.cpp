// bin: proto
// va: 0x002F5300
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5300 (Proto 0x002F5300, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004173F0;
extern "C" int DAT_004173F4;
extern "C" unsigned short DAT_004173FC;
extern "C" unsigned short DAT_004173FE;
extern "C" unsigned short DAT_00417402;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5300(void)
{
    DAT_004173F0 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004173F4);
    DAT_004173F4 = 0;
    DAT_004173FC = 0;
    DAT_004173FE = 0;
    DAT_00417402 = 0;
    return 0;
}
