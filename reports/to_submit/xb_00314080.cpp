// bin: xb
// va: 0x00314080
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314080 (0x00314080, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041F064[];
extern "C" Object DAT_0047B15C;
extern "C" char sub_00071B00[];

void __cdecl sub_00314080(void)
{
    DAT_0047B15C.sub_0006F740(0, (int)DAT_0041F064, (int)sub_00071B00, 0, 2, 2);
}
