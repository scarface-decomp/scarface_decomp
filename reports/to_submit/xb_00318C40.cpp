// bin: xb
// va: 0x00318C40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318C40 (0x00318C40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043049C[];
extern "C" char DAT_004304B8[];
extern "C" Object DAT_0048BBA8;
extern "C" char sub_00178860[];

void __cdecl sub_00318C40(void)
{
    DAT_0048BBA8.sub_0006F830((int)DAT_004304B8, (int)DAT_0043049C, (int)sub_00178860, 0, 2, 2);
}
