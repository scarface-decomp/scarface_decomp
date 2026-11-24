// bin: proto
// va: 0x002E5750
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5750 (Proto 0x002E5750, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00041090();
};

extern "C" Object DAT_0045C4DC;

void __cdecl sub_002E5750(void)
{
    DAT_0045C4DC.sub_00041090();
}
