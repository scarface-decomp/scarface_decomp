// bin: proto
// va: 0x002ED370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED370 (Proto 0x002ED370, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00428588;
extern "C" int DAT_004638BC;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002ED370(void)
{
    DAT_004638BC = sub_00200280(DAT_00428588);
}
