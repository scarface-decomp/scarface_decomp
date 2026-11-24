// bin: xb
// va: 0x0031FD00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FD00 (0x0031FD00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E1AC[];
extern "C" Object DAT_004920EC;
extern "C" char sub_0022FBF0[];

void __cdecl sub_0031FD00(void)
{
    DAT_004920EC.sub_0006F830(0, (int)DAT_0044E1AC, (int)sub_0022FBF0, 0, 1, 2);
}
