// bin: xb
// va: 0x0031E0A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E0A0 (0x0031E0A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C404[];
extern "C" char DAT_0044C414[];
extern "C" Object DAT_00490630;
extern "C" char sub_00215F80[];

void __cdecl sub_0031E0A0(void)
{
    DAT_00490630.sub_0006F830((int)DAT_0044C414, (int)DAT_0044C404, (int)sub_00215F80, 0, 3, 3);
}
