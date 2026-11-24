// bin: xb
// va: 0x00317300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317300 (0x00317300, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B108[];
extern "C" Object DAT_00489BCC;
extern "C" char sub_0011CFC0[];

void __cdecl sub_00317300(void)
{
    DAT_00489BCC.sub_0006F830(0, (int)DAT_0042B108, (int)sub_0011CFC0, 0, 3, 3);
}
