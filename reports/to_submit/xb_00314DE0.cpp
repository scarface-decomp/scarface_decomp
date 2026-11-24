// bin: xb
// va: 0x00314DE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314DE0 (0x00314DE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00423C60[];
extern "C" Object DAT_00481C4C;
extern "C" char sub_00098C40[];

void __cdecl sub_00314DE0(void)
{
    DAT_00481C4C.sub_0006F740(0, (int)DAT_00423C60, (int)sub_00098C40, 0, 3, 3);
}
