// bin: xb
// va: 0x00322420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322420 (0x00322420, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002F68D0();
};

extern "C" Object DAT_004C0548;

void __cdecl sub_00322420(void)
{
    DAT_004C0548.sub_002F68D0();
}
