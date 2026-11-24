// bin: xb
// va: 0x0031E000
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E000 (0x0031E000, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C25C[];
extern "C" char DAT_0044C270[];
extern "C" Object DAT_004905F4;
extern "C" char sub_00215CE0[];

void __cdecl sub_0031E000(void)
{
    DAT_004905F4.sub_0006F830((int)DAT_0044C270, (int)DAT_0044C25C, (int)sub_00215CE0, 0, 5, 5);
}
