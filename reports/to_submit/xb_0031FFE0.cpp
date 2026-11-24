// bin: xb
// va: 0x0031FFE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FFE0 (0x0031FFE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0044E4D0[];
extern "C" Object DAT_004924C8;
extern "C" char sub_002307B0[];

void __cdecl sub_0031FFE0(void)
{
    DAT_004924C8.sub_0006F740(0, (int)DAT_0044E4D0, (int)sub_002307B0, 0, 1, 1);
}
