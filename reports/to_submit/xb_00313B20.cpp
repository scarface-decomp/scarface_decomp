// bin: xb
// va: 0x00313B20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313B20 (0x00313B20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041E9D8[];
extern "C" Object DAT_00476D78;
extern "C" char sub_00068D60[];

void __cdecl sub_00313B20(void)
{
    DAT_00476D78.sub_0006F830(0, (int)DAT_0041E9D8, (int)sub_00068D60, 0, 1, 1);
}
