// bin: xb
// va: 0x0031C970
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C970 (0x0031C970, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_0043E2A8[];
extern "C" char DAT_0043E2BC[];
extern "C" Object DAT_0048F94C;
extern "C" char sub_001EE240[];

void __cdecl sub_0031C970(void)
{
    DAT_0048F94C.sub_0006F7E0((int)DAT_0043E2BC, (int)DAT_0043E2A8, (int)sub_001EE240, 0, 2, 2);
}
