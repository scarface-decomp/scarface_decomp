// bin: proto
// va: 0x002ED870
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED870 (Proto 0x002ED870, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FFCE0(int);
};

extern "C" Object DAT_0048E0FC;

void __cdecl sub_002ED870(void)
{
    DAT_0048E0FC.sub_001FFCE0(0);
}
