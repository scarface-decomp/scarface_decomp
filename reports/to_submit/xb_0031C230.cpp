// bin: xb
// va: 0x0031C230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C230 (0x0031C230, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043B92C[];
extern "C" char DAT_0043B93C[];
extern "C" Object DAT_0048F478;
extern "C" char sub_001D76F0[];

void __cdecl sub_0031C230(void)
{
    DAT_0048F478.sub_0006F830((int)DAT_0043B93C, (int)DAT_0043B92C, (int)sub_001D76F0, 0, 3, 3);
}
