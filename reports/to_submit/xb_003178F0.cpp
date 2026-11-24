// bin: xb
// va: 0x003178F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003178F0 (0x003178F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_0042E85C[];
extern "C" char DAT_0042E86C[];
extern "C" Object DAT_0048A3C0;
extern "C" char sub_0015C6C0[];

void __cdecl sub_003178F0(void)
{
    DAT_0048A3C0.sub_0006F7E0((int)DAT_0042E86C, (int)DAT_0042E85C, (int)sub_0015C6C0, 0, 2, 2);
}
