// bin: proto
// va: 0x002E80F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E80F0 (Proto 0x002E80F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411630[];
extern "C" char DAT_00411640[];
extern "C" Object DAT_0045FC0C;
extern "C" char sub_0018BA10[];

void __cdecl sub_002E80F0(void)
{
    DAT_0045FC0C.sub_00065550((int)DAT_00411640, (int)DAT_00411630, (int)sub_0018BA10, 0, 2, 2);
}
