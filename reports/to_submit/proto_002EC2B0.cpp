// bin: proto
// va: 0x002EC2B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC2B0 (Proto 0x002EC2B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004274CC[];
extern "C" Object DAT_00462C1C;
extern "C" char sub_001E5B50[];

void __cdecl sub_002EC2B0(void)
{
    DAT_00462C1C.sub_00065550(0, (int)DAT_004274CC, (int)sub_001E5B50, 0, 2, 2);
}
