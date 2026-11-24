// bin: proto
// va: 0x002ED560
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED560 (Proto 0x002ED560, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FFCE0(int);
};

extern "C" Object DAT_00463B70;

void __cdecl sub_002ED560(void)
{
    DAT_00463B70.sub_001FFCE0(0);
}
