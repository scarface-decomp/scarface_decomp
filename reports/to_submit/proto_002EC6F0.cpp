// bin: proto
// va: 0x002EC6F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC6F0 (Proto 0x002EC6F0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038B460[];
extern "C" int DAT_00462E90;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_002EC6F0(void)
{
    DAT_00462E90 = sub_002014E0((int)DAT_0038B460, 0);
}
