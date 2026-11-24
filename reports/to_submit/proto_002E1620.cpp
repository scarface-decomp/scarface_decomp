// bin: proto
// va: 0x002E1620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1620 (Proto 0x002E1620, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00041140();
};

extern "C" Object DAT_0044A57C;

void __cdecl sub_002E1620(void)
{
    DAT_0044A57C.sub_00041140();
}
