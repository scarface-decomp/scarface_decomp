// bin: xb
// va: 0x00318A40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318A40 (0x00318A40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00430254[];
extern "C" char DAT_00430270[];
extern "C" Object DAT_0048B8E8;
extern "C" char sub_00178690[];

void __cdecl sub_00318A40(void)
{
    DAT_0048B8E8.sub_0006F740((int)DAT_00430270, (int)DAT_00430254, (int)sub_00178690, 0, 2, 2);
}
