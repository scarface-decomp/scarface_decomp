// bin: proto
// va: 0x002F08A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F08A0 (Proto 0x002F08A0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002C4070();
};

extern "C" Object DAT_004915D8;

void __cdecl sub_002F08A0(void)
{
    DAT_004915D8.sub_002C4070();
}
