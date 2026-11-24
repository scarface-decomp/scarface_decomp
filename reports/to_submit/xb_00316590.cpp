// bin: xb
// va: 0x00316590
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316590 (0x00316590, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_004277F8[];
extern "C" Object DAT_004890F0;
extern "C" char sub_000EEA60[];

void __cdecl sub_00316590(void)
{
    DAT_004890F0.sub_0006F7E0(0, (int)DAT_004277F8, (int)sub_000EEA60, 0, 4, 4);
}
