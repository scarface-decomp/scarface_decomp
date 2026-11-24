// bin: xb
// va: 0x0031FF20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FF20 (0x0031FF20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E430[];
extern "C" Object DAT_004923C0;
extern "C" char sub_002306E0[];

void __cdecl sub_0031FF20(void)
{
    DAT_004923C0.sub_0006F830(0, (int)DAT_0044E430, (int)sub_002306E0, 0, 3, 3);
}
