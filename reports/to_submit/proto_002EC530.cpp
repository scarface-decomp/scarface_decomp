// bin: proto
// va: 0x002EC530
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC530 (Proto 0x002EC530, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003981DC[];
extern "C" int DAT_00462E20;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC530(void)
{
    DAT_00462E20 = sub_002014E0((int)DAT_003981DC, 0);
}
