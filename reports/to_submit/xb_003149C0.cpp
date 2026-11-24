// bin: xb
// va: 0x003149C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003149C0 (0x003149C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A4288[];
extern "C" Object DAT_004815D8;
extern "C" char sub_0008C7B0[];

void __cdecl sub_003149C0(void)
{
    DAT_004815D8.sub_000EB3A0(48, 34, 25, 35, 5, (int)DAT_003A4288, (int)sub_0008C7B0, 509, 3, 1);
}
