// bin: xb
// va: 0x003147F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003147F0 (0x003147F0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3F0(int, int, int);
};

extern "C" Object DAT_00481174;
extern "C" char sub_00087FA0[];

void __cdecl sub_003147F0(void)
{
    DAT_00481174.sub_000EB3F0(20, (int)sub_00087FA0, 0);
}
