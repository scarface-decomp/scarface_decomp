// bin: xb
// va: 0x003126C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003126C0 (0x003126C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041AAC8[];
extern "C" char DAT_0041AAD8[];
extern "C" Object DAT_00471A04;
extern "C" char sub_00024DC0[];

void __cdecl sub_003126C0(void)
{
    DAT_00471A04.sub_0006F830((int)DAT_0041AAD8, (int)DAT_0041AAC8, (int)sub_00024DC0, 0, 3, 3);
}
