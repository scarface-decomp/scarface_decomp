// bin: xb
// va: 0x00317C50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317C50 (0x00317C50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F16C[];
extern "C" char DAT_0042F17C[];
extern "C" Object DAT_0048A7EC;
extern "C" char sub_0015D430[];

void __cdecl sub_00317C50(void)
{
    DAT_0048A7EC.sub_0006F830((int)DAT_0042F17C, (int)DAT_0042F16C, (int)sub_0015D430, 0, 3, 3);
}
