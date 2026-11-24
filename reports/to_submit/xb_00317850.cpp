// bin: xb
// va: 0x00317850
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317850 (0x00317850, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042E740[];
extern "C" char DAT_0042E758[];
extern "C" Object DAT_0048A310;
extern "C" char sub_0015C360[];

void __cdecl sub_00317850(void)
{
    DAT_0048A310.sub_0006F830((int)DAT_0042E758, (int)DAT_0042E740, (int)sub_0015C360, 0, 3, 6);
}
