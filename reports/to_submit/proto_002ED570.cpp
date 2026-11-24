// bin: proto
// va: 0x002ED570
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED570 (Proto 0x002ED570, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00463B70[];
extern "C" int DAT_00463B78;

void __cdecl sub_002ED570(void)
{
    DAT_00463B78 = (int)DAT_00463B70;
}
