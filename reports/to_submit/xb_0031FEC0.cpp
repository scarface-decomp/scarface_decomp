// bin: xb
// va: 0x0031FEC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FEC0 (0x0031FEC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E3DC[];
extern "C" Object DAT_0049233C;
extern "C" char sub_00230670[];

void __cdecl sub_0031FEC0(void)
{
    DAT_0049233C.sub_0006F830(0, (int)DAT_0044E3DC, (int)sub_00230670, 0, 2, 2);
}
