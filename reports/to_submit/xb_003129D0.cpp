// bin: xb
// va: 0x003129D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003129D0 (0x003129D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041B784[];
extern "C" char DAT_0041B78C[];
extern "C" Object DAT_0047427C;
extern "C" char sub_0002D610[];

void __cdecl sub_003129D0(void)
{
    DAT_0047427C.sub_0006F790((int)DAT_0041B78C, (int)DAT_0041B784, (int)sub_0002D610, 0, 2, 2);
}
