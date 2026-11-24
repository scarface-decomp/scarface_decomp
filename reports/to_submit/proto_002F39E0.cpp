// bin: proto
// va: 0x002F39E0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F39E0 (Proto 0x002F39E0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004105CC;
extern "C" int DAT_004105D0;
extern "C" unsigned short DAT_004105D8;
extern "C" unsigned short DAT_004105DA;
extern "C" unsigned short DAT_004105DE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F39E0(void)
{
    DAT_004105CC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004105D0);
    DAT_004105D0 = 0;
    DAT_004105D8 = 0;
    DAT_004105DA = 0;
    DAT_004105DE = 0;
    return 0;
}
