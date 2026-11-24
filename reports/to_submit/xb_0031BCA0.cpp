// bin: xb
// va: 0x0031BCA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BCA0 (0x0031BCA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC08[];
extern "C" char DAT_0043AC10[];
extern "C" Object DAT_0048EF24;
extern "C" char sub_001D3410[];

void __cdecl sub_0031BCA0(void)
{
    DAT_0048EF24.sub_0006F830((int)DAT_0043AC10, (int)DAT_0043AC08, (int)sub_001D3410, 0, 5, 5);
}
