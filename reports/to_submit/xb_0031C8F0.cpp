// bin: xb
// va: 0x0031C8F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C8F0 (0x0031C8F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E230[];
extern "C" char DAT_0043E23C[];
extern "C" Object DAT_0048F89C;
extern "C" char sub_001EE1C0[];

void __cdecl sub_0031C8F0(void)
{
    DAT_0048F89C.sub_0006F830((int)DAT_0043E23C, (int)DAT_0043E230, (int)sub_001EE1C0, 0, 3, 3);
}
