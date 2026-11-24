// bin: xb
// va: 0x003156C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003156C0 (0x003156C0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB410(int, int, int);
};

extern "C" Object DAT_004872D1;
extern "C" char sub_000CF240[];

void __cdecl sub_003156C0(void)
{
    DAT_004872D1.sub_000EB410(20, (int)sub_000CF240, 0);
}
