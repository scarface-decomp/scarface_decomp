// bin: xb
// va: 0x0031FFA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FFA0 (0x0031FFA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E4A0[];
extern "C" Object DAT_00492470;
extern "C" char sub_00230780[];

void __cdecl sub_0031FFA0(void)
{
    DAT_00492470.sub_0006F830(0, (int)DAT_0044E4A0, (int)sub_00230780, 0, 1, 1);
}
