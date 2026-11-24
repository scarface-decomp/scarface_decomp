// bin: xb
// va: 0x0031A540
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A540 (0x0031A540, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004374CC[];
extern "C" Object DAT_0048DCEC;
extern "C" char sub_001BEBA0[];

void __cdecl sub_0031A540(void)
{
    DAT_0048DCEC.sub_0006F830(0, (int)DAT_004374CC, (int)sub_001BEBA0, 0, 9, 9);
}
