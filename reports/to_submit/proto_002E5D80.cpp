// bin: proto
// va: 0x002E5D80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5D80 (Proto 0x002E5D80, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00391C58[];
extern "C" int DAT_0045CBFC;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002E5D80(void)
{
    DAT_0045CBFC = sub_002014E0((int)DAT_00391C58, 0);
}
