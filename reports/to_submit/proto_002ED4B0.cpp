// bin: proto
// va: 0x002ED4B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED4B0 (Proto 0x002ED4B0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004285C0;
extern "C" int DAT_004638EC;
extern "C" int __cdecl sub_00200280(int);

void __cdecl sub_002ED4B0(void)
{
    DAT_004638EC = sub_00200280(DAT_004285C0);
}
