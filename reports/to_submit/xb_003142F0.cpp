// bin: xb
// va: 0x003142F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003142F0 (0x003142F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004221EC[];
extern "C" Object DAT_00480C0C;
extern "C" char sub_00076FF0[];

void __cdecl sub_003142F0(void)
{
    DAT_00480C0C.sub_0006F830(0, (int)DAT_004221EC, (int)sub_00076FF0, 0, 3, 3);
}
