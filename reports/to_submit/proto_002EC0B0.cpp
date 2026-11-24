// bin: proto
// va: 0x002EC0B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC0B0 (Proto 0x002EC0B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00427320[];
extern "C" Object DAT_0046295C;
extern "C" char sub_001E5890[];

void __cdecl sub_002EC0B0(void)
{
    DAT_0046295C.sub_000654B0(0, (int)DAT_00427320, (int)sub_001E5890, 0, 2, 2);
}
