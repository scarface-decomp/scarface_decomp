// bin: proto
// va: 0x002ED430
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED430 (Proto 0x002ED430, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004285C4;
extern "C" int DAT_004638E4;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002ED430(void)
{
    DAT_004638E4 = sub_00200280(DAT_004285C4);
}
