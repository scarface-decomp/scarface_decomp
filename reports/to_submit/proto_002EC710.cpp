// bin: proto
// va: 0x002EC710
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC710 (Proto 0x002EC710, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AB0E8[];
extern "C" int DAT_00462E98;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC710(void)
{
    DAT_00462E98 = sub_002014E0((int)DAT_003AB0E8, 0);
}
