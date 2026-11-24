// bin: xb
// va: 0x00314B70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314B70 (0x00314B70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423294[];
extern "C" Object DAT_00481888;
extern "C" char sub_0008FC20[];

void __cdecl sub_00314B70(void)
{
    DAT_00481888.sub_0006F740(0, (int)DAT_00423294, (int)sub_0008FC20, 0, 1, 1);
}
