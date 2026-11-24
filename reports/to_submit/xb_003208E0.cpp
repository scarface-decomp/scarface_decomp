// bin: xb
// va: 0x003208E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003208E0 (0x003208E0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002427E0(int);
};

extern "C" Object DAT_00492C60;

void __cdecl sub_003208E0(void)
{
    DAT_00492C60.sub_002427E0(0);
}
