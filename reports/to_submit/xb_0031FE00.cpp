// bin: xb
// va: 0x0031FE00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FE00 (0x0031FE00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044E274[];
extern "C" Object DAT_0049224C;
extern "C" char sub_0022D9C0[];

void __cdecl sub_0031FE00(void)
{
    DAT_0049224C.sub_0006F880(0, (int)DAT_0044E274, (int)sub_0022D9C0, 0, 1, 1);
}
