// bin: xb
// va: 0x00317970
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317970 (0x00317970, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042E8E0[];
extern "C" char DAT_0042E8F4[];
extern "C" Object DAT_0048A470;
extern "C" char sub_0015C730[];

void __cdecl sub_00317970(void)
{
    DAT_0048A470.sub_0006F830((int)DAT_0042E8F4, (int)DAT_0042E8E0, (int)sub_0015C730, 0, 6, 6);
}
