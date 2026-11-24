// bin: xb
// va: 0x00313FC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313FC0 (0x00313FC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041F01C[];
extern "C" Object DAT_0047B054;
extern "C" char sub_00070D20[];

void __cdecl sub_00313FC0(void)
{
    DAT_0047B054.sub_0006F790(0, (int)DAT_0041F01C, (int)sub_00070D20, 0, 2, 2);
}
