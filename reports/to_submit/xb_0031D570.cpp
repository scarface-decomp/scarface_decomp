// bin: xb
// va: 0x0031D570
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D570 (0x0031D570, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044252C[];
extern "C" char DAT_00442540[];
extern "C" Object DAT_00490488;
extern "C" char sub_00203C90[];

void __cdecl sub_0031D570(void)
{
    DAT_00490488.sub_0006F830((int)DAT_00442540, (int)DAT_0044252C, (int)sub_00203C90, 0, 3, 3);
}
