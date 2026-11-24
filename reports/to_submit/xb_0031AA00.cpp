// bin: xb
// va: 0x0031AA00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AA00 (0x0031AA00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437B0C[];
extern "C" char DAT_00437B14[];
extern "C" Object DAT_0048E26C;
extern "C" char sub_001BF560[];

void __cdecl sub_0031AA00(void)
{
    DAT_0048E26C.sub_0006F830((int)DAT_00437B14, (int)DAT_00437B0C, (int)sub_001BF560, 0, 3, 3);
}
