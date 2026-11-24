// bin: xb
// va: 0x0031CC90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CC90 (0x0031CC90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E980[];
extern "C" char DAT_0043E994[];
extern "C" Object DAT_0048FC94;
extern "C" char sub_001EEA40[];

void __cdecl sub_0031CC90(void)
{
    DAT_0048FC94.sub_0006F830((int)DAT_0043E994, (int)DAT_0043E980, (int)sub_001EEA40, 0, 3, 3);
}
