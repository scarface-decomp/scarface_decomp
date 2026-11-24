// bin: xb
// va: 0x003165F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003165F0 (0x003165F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_00427828[];
extern "C" Object DAT_00489174;
extern "C" char sub_000EEAE0[];

void __cdecl sub_003165F0(void)
{
    DAT_00489174.sub_0006F7E0(0, (int)DAT_00427828, (int)sub_000EEAE0, 0, 2, 2);
}
