// bin: proto
// va: 0x002F75B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F75B0 (Proto 0x002F75B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004265CC;
extern "C" int DAT_004265D0;
extern "C" unsigned short DAT_004265D8;
extern "C" unsigned short DAT_004265DA;
extern "C" unsigned short DAT_004265DE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F75B0(void)
{
    DAT_004265CC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004265D0);
    DAT_004265D0 = 0;
    DAT_004265D8 = 0;
    DAT_004265DA = 0;
    DAT_004265DE = 0;
    return 0;
}
