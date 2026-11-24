// bin: xb
// va: 0x00312640
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312640 (0x00312640, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041AA74[];
extern "C" Object DAT_00471954;
extern "C" char sub_00024C30[];

void __cdecl sub_00312640(void)
{
    DAT_00471954.sub_0006F740(0, (int)DAT_0041AA74, (int)sub_00024C30, 0, 1, 1);
}
