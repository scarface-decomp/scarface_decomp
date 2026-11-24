// bin: xb
// va: 0x00318FE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318FE0 (0x00318FE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00431584[];
extern "C" char DAT_00431594[];
extern "C" Object DAT_0048BD8C;
extern "C" char sub_0017A910[];

void __cdecl sub_00318FE0(void)
{
    DAT_0048BD8C.sub_0006F740((int)DAT_00431594, (int)DAT_00431584, (int)sub_0017A910, 0, 3, 5);
}
