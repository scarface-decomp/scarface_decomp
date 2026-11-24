// bin: proto
// va: 0x002F5890
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F5890 (Proto 0x002F5890, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004191CC;
extern "C" int DAT_004191D0;
extern "C" unsigned short DAT_004191D8;
extern "C" unsigned short DAT_004191DA;
extern "C" unsigned short DAT_004191DE;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F5890(void)
{
    DAT_004191CC = (int)DAT_0037CCF4;
    sub_00025160(DAT_004191D0);
    DAT_004191D0 = 0;
    DAT_004191D8 = 0;
    DAT_004191DA = 0;
    DAT_004191DE = 0;
    return 0;
}
