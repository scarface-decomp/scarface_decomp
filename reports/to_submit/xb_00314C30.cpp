// bin: xb
// va: 0x00314C30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314C30 (0x00314C30, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A4318[];
extern "C" Object DAT_00481B30;
extern "C" char sub_00091A60[];

void __cdecl sub_00314C30(void)
{
    DAT_00481B30.sub_000EB3A0(38, 4, 15, 66, 16, (int)DAT_003A4318, (int)sub_00091A60, 248, 0, 1);
}
