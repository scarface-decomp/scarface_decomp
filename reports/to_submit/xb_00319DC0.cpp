// bin: xb
// va: 0x00319DC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319DC0 (0x00319DC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436908[];
extern "C" Object DAT_0048D5E0;
extern "C" char sub_001BD470[];

void __cdecl sub_00319DC0(void)
{
    DAT_0048D5E0.sub_0006F830(0, (int)DAT_00436908, (int)sub_001BD470, 0, 1, 1);
}
