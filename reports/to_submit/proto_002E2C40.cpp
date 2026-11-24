// bin: proto
// va: 0x002E2C40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2C40 (Proto 0x002E2C40, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038375C[];
extern "C" char DAT_0038376C[];
extern "C" char DAT_0038377C[];
extern "C" int DAT_00453BD4;
extern "C" int DAT_00453BD8;
extern "C" int DAT_00453BDC;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E2C40(void)
{
    DAT_00453BD4 = sub_002014E0((int)DAT_0038377C, 0);
    DAT_00453BD8 = sub_002014E0((int)DAT_0038376C, 0);
    DAT_00453BDC = sub_002014E0((int)DAT_0038375C, 0);
}
