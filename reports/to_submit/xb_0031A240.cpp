// bin: xb
// va: 0x0031A240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A240 (0x0031A240, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436FF0[];
extern "C" char DAT_00437004[];
extern "C" Object DAT_0048DA00;
extern "C" char sub_001BE450[];

void __cdecl sub_0031A240(void)
{
    DAT_0048DA00.sub_0006F830((int)DAT_00437004, (int)DAT_00436FF0, (int)sub_001BE450, 0, 3, 3);
}
