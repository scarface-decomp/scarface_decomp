// bin: proto
// va: 0x002ECA50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECA50 (Proto 0x002ECA50, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039838C[];
extern "C" int DAT_00462FB4;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002ECA50(void)
{
    DAT_00462FB4 = sub_002014E0((int)DAT_0039838C, 0);
}
