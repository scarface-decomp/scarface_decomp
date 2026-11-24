// bin: xb
// va: 0x00311A90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311A90 (0x00311A90, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039D728[];
extern "C" int DAT_00419578;
extern "C" Object DAT_0046C0C0;
extern "C" char sub_00016030[];

void __cdecl sub_00311A90(void)
{
    DAT_0046C0C0.sub_000EB3A0(22, 24, 31, 62, 33, (int)DAT_0039D728, (int)sub_00016030, DAT_00419578, 3, 0);
}
