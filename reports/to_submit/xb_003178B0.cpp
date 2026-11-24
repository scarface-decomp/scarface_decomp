// bin: xb
// va: 0x003178B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003178B0 (0x003178B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042E7B0[];
extern "C" char DAT_0042E7C4[];
extern "C" Object DAT_0048A394;
extern "C" char sub_0015C550[];

void __cdecl sub_003178B0(void)
{
    DAT_0048A394.sub_0006F830((int)DAT_0042E7C4, (int)DAT_0042E7B0, (int)sub_0015C550, 0, 3, 3);
}
