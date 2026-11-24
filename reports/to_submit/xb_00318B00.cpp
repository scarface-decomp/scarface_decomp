// bin: xb
// va: 0x00318B00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318B00 (0x00318B00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043032C[];
extern "C" char DAT_00430340[];
extern "C" Object DAT_0048B9F0;
extern "C" char sub_00178750[];

void __cdecl sub_00318B00(void)
{
    DAT_0048B9F0.sub_0006F830((int)DAT_00430340, (int)DAT_0043032C, (int)sub_00178750, 0, 2, 3);
}
