// bin: xb
// va: 0x0031BCC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BCC0 (0x0031BCC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC1C[];
extern "C" char DAT_0043AC28[];
extern "C" Object DAT_0048EF50;
extern "C" char sub_001D3450[];

void __cdecl sub_0031BCC0(void)
{
    DAT_0048EF50.sub_0006F880((int)DAT_0043AC28, (int)DAT_0043AC1C, (int)sub_001D3450, 0, 2, 2);
}
