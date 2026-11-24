// bin: xb
// va: 0x00316550
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316550 (0x00316550, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004277E0[];
extern "C" Object DAT_00489098;
extern "C" char sub_000EE9C0[];

void __cdecl sub_00316550(void)
{
    DAT_00489098.sub_0006F790(0, (int)DAT_004277E0, (int)sub_000EE9C0, 0, 2, 3);
}
