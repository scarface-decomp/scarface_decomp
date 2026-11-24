// bin: xb
// va: 0x00320920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320920 (0x00320920, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00492ED8[];
extern "C" int DAT_00492EE0;

void __cdecl sub_00320920(void)
{
    DAT_00492EE0 = (int)DAT_00492ED8;
}
