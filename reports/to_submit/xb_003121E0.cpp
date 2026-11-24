// bin: xb
// va: 0x003121E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003121E0 (0x003121E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419F7C[];
extern "C" char DAT_00419F8C[];
extern "C" Object DAT_004715A8;
extern "C" char sub_00020960[];

void __cdecl sub_003121E0(void)
{
    DAT_004715A8.sub_0006F830((int)DAT_00419F8C, (int)DAT_00419F7C, (int)sub_00020960, 0, 5, 5);
}
