// bin: xb
// va: 0x00311860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311860 (0x00311860, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3F0(int, int, int);
};

extern "C" Object DAT_00467FA4;
extern "C" char sub_00011000[];

void __cdecl sub_00311860(void)
{
    DAT_00467FA4.sub_000EB3F0(11, (int)sub_00011000, 0);
}
