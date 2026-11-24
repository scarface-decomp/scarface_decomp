// bin: xb
// va: 0x003196D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003196D0 (0x003196D0, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001AC330();
};

extern "C" Object DAT_0048CF50;

void __cdecl sub_003196D0(void)
{
    DAT_0048CF50.sub_001AC330();
}
