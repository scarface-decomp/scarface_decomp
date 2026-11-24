// bin: xb
// va: 0x00314B50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314B50 (0x00314B50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423280[];
extern "C" Object DAT_0048185C;
extern "C" char sub_0008FCE0[];

void __cdecl sub_00314B50(void)
{
    DAT_0048185C.sub_0006F740(0, (int)DAT_00423280, (int)sub_0008FCE0, 0, 2, 2);
}
