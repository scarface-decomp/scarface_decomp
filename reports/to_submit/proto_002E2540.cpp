// bin: proto
// va: 0x002E2540
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2540 (Proto 0x002E2540, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FCFA8[];
extern "C" Object DAT_00453380;
extern "C" char sub_0006C740[];

void __cdecl sub_002E2540(void)
{
    DAT_00453380.sub_000655A0(0, (int)DAT_003FCFA8, (int)sub_0006C740, 0, 1, 1);
}
