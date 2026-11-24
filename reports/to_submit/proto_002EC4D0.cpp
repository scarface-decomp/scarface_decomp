// bin: proto
// va: 0x002EC4D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC4D0 (Proto 0x002EC4D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00398230[];
extern "C" int DAT_00462E08;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC4D0(void)
{
    DAT_00462E08 = sub_002014E0((int)DAT_00398230, 0);
}
