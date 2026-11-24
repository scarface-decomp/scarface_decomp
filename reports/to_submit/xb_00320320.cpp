// bin: xb
// va: 0x00320320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320320 (0x00320320, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D3374[];
extern "C" Object DAT_00492900;
extern "C" char sub_00232850[];

void __cdecl sub_00320320(void)
{
    DAT_00492900.sub_000EB3A0(7, 6, 22, 89, 8, (int)DAT_003D3374, (int)sub_00232850, 509, 3, 0);
}
