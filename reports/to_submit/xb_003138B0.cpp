// bin: xb
// va: 0x003138B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003138B0 (0x003138B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A2264[];
extern "C" Object DAT_00476A58;
extern "C" char sub_00068740[];

void __cdecl sub_003138B0(void)
{
    DAT_00476A58.sub_000EB3A0(4, 20, 36, 74, 45, (int)DAT_003A2264, (int)sub_00068740, 196, 0, 0);
}
