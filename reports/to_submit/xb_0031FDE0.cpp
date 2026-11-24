// bin: xb
// va: 0x0031FDE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FDE0 (0x0031FDE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E25C[];
extern "C" Object DAT_00492220;
extern "C" char sub_0022D9B0[];

void __cdecl sub_0031FDE0(void)
{
    DAT_00492220.sub_0006F830(0, (int)DAT_0044E25C, (int)sub_0022D9B0, 0, 1, 1);
}
