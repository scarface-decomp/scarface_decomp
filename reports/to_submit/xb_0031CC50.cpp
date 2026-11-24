// bin: xb
// va: 0x0031CC50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CC50 (0x0031CC50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E930[];
extern "C" char DAT_0043E94C[];
extern "C" Object DAT_0048FC3C;
extern "C" char sub_001EEA10[];

void __cdecl sub_0031CC50(void)
{
    DAT_0048FC3C.sub_0006F830((int)DAT_0043E94C, (int)DAT_0043E930, (int)sub_001EEA10, 0, 3, 3);
}
