// bin: xb
// va: 0x00314810
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314810 (0x00314810, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB410(int, int, int);
};

extern "C" Object DAT_00481175;
extern "C" char sub_00088000[];

void __cdecl sub_00314810(void)
{
    DAT_00481175.sub_000EB410(35, (int)sub_00088000, 0);
}
