// bin: xb
// va: 0x00319400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319400 (0x00319400, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB410(int, int, int);
};

extern "C" Object DAT_0048BFED;
extern "C" char sub_002A9290[];

void __cdecl sub_00319400(void)
{
    DAT_0048BFED.sub_000EB410(14, (int)sub_002A9290, 0);
}
