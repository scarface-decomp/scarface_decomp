// bin: xb
// va: 0x00315230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315230 (0x00315230, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3F0(int, int, int);
};

extern "C" Object DAT_004867D4;
extern "C" char sub_000ABAA0[];

void __cdecl sub_00315230(void)
{
    DAT_004867D4.sub_000EB3F0(19, (int)sub_000ABAA0, 0);
}
