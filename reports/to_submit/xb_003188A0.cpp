// bin: xb
// va: 0x003188A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003188A0 (0x003188A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430088[];
extern "C" char DAT_00430094[];
extern "C" Object DAT_0048B6AC;
extern "C" char sub_00178F20[];

void __cdecl sub_003188A0(void)
{
    DAT_0048B6AC.sub_0006F830((int)DAT_00430094, (int)DAT_00430088, (int)sub_00178F20, 0, 3, 4);
}
