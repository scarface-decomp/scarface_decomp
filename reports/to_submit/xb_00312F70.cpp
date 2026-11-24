// bin: xb
// va: 0x00312F70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312F70 (0x00312F70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041C388[];
extern "C" Object DAT_00474A58;
extern "C" char sub_002A9290[];

void __cdecl sub_00312F70(void)
{
    DAT_00474A58.sub_0006F830(0, (int)DAT_0041C388, (int)sub_002A9290, 0, 3, 3);
}
