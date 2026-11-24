// bin: proto
// va: 0x002EB2D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB2D0 (Proto 0x002EB2D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425F00[];
extern "C" char DAT_00425F10[];
extern "C" Object DAT_00461AA0;
extern "C" char sub_001DAAD0[];

void __cdecl sub_002EB2D0(void)
{
    DAT_00461AA0.sub_00065550((int)DAT_00425F10, (int)DAT_00425F00, (int)sub_001DAAD0, 0, 4, 4);
}
