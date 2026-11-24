// bin: xb
// va: 0x003182E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003182E0 (0x003182E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FA20[];
extern "C" char DAT_0042FA34[];
extern "C" Object DAT_0048AEC4;
extern "C" char sub_00177FF0[];

void __cdecl sub_003182E0(void)
{
    DAT_0048AEC4.sub_0006F830((int)DAT_0042FA34, (int)DAT_0042FA20, (int)sub_00177FF0, 0, 2, 2);
}
