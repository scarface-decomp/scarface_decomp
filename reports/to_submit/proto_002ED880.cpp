// bin: proto
// va: 0x002ED880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED880 (Proto 0x002ED880, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FFCE0(int);
};

extern "C" Object DAT_0048E104;

void __cdecl sub_002ED880(void)
{
    DAT_0048E104.sub_001FFCE0(0);
}
