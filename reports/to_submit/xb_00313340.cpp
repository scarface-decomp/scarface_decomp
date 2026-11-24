// bin: xb
// va: 0x00313340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313340 (0x00313340, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041D2FC[];
extern "C" Object DAT_0047582C;
extern "C" char sub_0004E2E0[];

void __cdecl sub_00313340(void)
{
    DAT_0047582C.sub_0006F830(0, (int)DAT_0041D2FC, (int)sub_0004E2E0, 0, 6, 6);
}
