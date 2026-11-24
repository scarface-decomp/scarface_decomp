// bin: xb
// va: 0x0031AC60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AC60 (0x0031AC60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437EEC[];
extern "C" char DAT_00437EF4[];
extern "C" Object DAT_0048E47C;
extern "C" char sub_001BFBD0[];

void __cdecl sub_0031AC60(void)
{
    DAT_0048E47C.sub_0006F830((int)DAT_00437EF4, (int)DAT_00437EEC, (int)sub_001BFBD0, 0, 3, 3);
}
