// bin: xb
// va: 0x00312370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312370 (0x00312370, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039EE40[];
extern "C" Object DAT_00471798;
extern "C" char sub_00024440[];

void __cdecl sub_00312370(void)
{
    DAT_00471798.sub_000EB3A0(39, 7, 17, 67, 15, (int)DAT_0039EE40, (int)sub_00024440, 4, 0, 1);
}
