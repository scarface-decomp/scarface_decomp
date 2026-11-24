// bin: xb
// va: 0x0031FD80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FD80 (0x0031FD80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E220[];
extern "C" Object DAT_0049219C;
extern "C" char sub_0022D980[];

void __cdecl sub_0031FD80(void)
{
    DAT_0049219C.sub_0006F830(0, (int)DAT_0044E220, (int)sub_0022D980, 0, 2, 2);
}
