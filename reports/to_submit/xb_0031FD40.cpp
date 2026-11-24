// bin: xb
// va: 0x0031FD40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FD40 (0x0031FD40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E1F0[];
extern "C" Object DAT_00492144;
extern "C" char sub_0022FC50[];

void __cdecl sub_0031FD40(void)
{
    DAT_00492144.sub_0006F830(0, (int)DAT_0044E1F0, (int)sub_0022FC50, 0, 3, 3);
}
