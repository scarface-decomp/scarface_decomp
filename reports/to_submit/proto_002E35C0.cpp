// bin: proto
// va: 0x002E35C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E35C0 (Proto 0x002E35C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF508[];
extern "C" char DAT_003FF518[];
extern "C" Object DAT_0045972C;
extern "C" char sub_000BAD70[];

void __cdecl sub_002E35C0(void)
{
    DAT_0045972C.sub_00065550((int)DAT_003FF518, (int)DAT_003FF508, (int)sub_000BAD70, 0, 4, 4);
}
