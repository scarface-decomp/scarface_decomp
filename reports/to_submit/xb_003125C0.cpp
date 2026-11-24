// bin: xb
// va: 0x003125C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003125C0 (0x003125C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041A9FC[];
extern "C" Object DAT_004718A4;
extern "C" char sub_00024B40[];

void __cdecl sub_003125C0(void)
{
    DAT_004718A4.sub_0006F790(0, (int)DAT_0041A9FC, (int)sub_00024B40, 0, 3, 3);
}
