// bin: xb
// va: 0x00314E40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314E40 (0x00314E40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_00423C94[];
extern "C" Object DAT_00481CE0;
extern "C" char sub_00098D60[];

void __cdecl sub_00314E40(void)
{
    DAT_00481CE0.sub_0006F7E0(0, (int)DAT_00423C94, (int)sub_00098D60, 0, 2, 2);
}
