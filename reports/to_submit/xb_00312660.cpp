// bin: xb
// va: 0x00312660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312660 (0x00312660, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041AA88[];
extern "C" Object DAT_00471980;
extern "C" char sub_00024C50[];

void __cdecl sub_00312660(void)
{
    DAT_00471980.sub_0006F740(0, (int)DAT_0041AA88, (int)sub_00024C50, 0, 2, 2);
}
