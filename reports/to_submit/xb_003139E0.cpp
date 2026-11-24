// bin: xb
// va: 0x003139E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003139E0 (0x003139E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041E94C[];
extern "C" Object DAT_00476BC0;
extern "C" char sub_002A9290[];

void __cdecl sub_003139E0(void)
{
    DAT_00476BC0.sub_0006F830(0, (int)DAT_0041E94C, (int)sub_002A9290, 0, 3, 63);
}
