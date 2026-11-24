// bin: xb
// va: 0x0031CC10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CC10 (0x0031CC10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E8E0[];
extern "C" char DAT_0043E8F4[];
extern "C" Object DAT_0048FBE4;
extern "C" char sub_001EE9E0[];

void __cdecl sub_0031CC10(void)
{
    DAT_0048FBE4.sub_0006F830((int)DAT_0043E8F4, (int)DAT_0043E8E0, (int)sub_001EE9E0, 0, 3, 3);
}
