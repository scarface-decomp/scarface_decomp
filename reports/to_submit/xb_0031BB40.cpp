// bin: xb
// va: 0x0031BB40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BB40 (0x0031BB40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043A70C[];
extern "C" char DAT_0043A720[];
extern "C" Object DAT_0048EE1C;
extern "C" char sub_001D29B0[];

void __cdecl sub_0031BB40(void)
{
    DAT_0048EE1C.sub_0006F790((int)DAT_0043A720, (int)DAT_0043A70C, (int)sub_001D29B0, 0, 3, 3);
}
