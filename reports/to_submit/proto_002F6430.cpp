// bin: proto
// va: 0x002F6430
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6430 (Proto 0x002F6430, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041DF28;
extern "C" int DAT_0041DF2C;
extern "C" unsigned short DAT_0041DF34;
extern "C" unsigned short DAT_0041DF36;
extern "C" unsigned short DAT_0041DF3A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6430(void)
{
    DAT_0041DF28 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041DF2C);
    DAT_0041DF2C = 0;
    DAT_0041DF34 = 0;
    DAT_0041DF36 = 0;
    DAT_0041DF3A = 0;
    return 0;
}
