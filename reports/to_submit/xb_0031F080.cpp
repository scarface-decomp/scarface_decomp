// bin: xb
// va: 0x0031F080
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F080 (0x0031F080, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044D908[];
extern "C" Object DAT_0049179C;
extern "C" char sub_00222970[];

void __cdecl sub_0031F080(void)
{
    DAT_0049179C.sub_0006F830(0, (int)DAT_0044D908, (int)sub_00222970, 0, 1, 1);
}
