// bin: proto
// va: 0x002EC4B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC4B0 (Proto 0x002EC4B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039824C[];
extern "C" int DAT_00462E00;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC4B0(void)
{
    DAT_00462E00 = sub_002014E0((int)DAT_0039824C, 0);
}
