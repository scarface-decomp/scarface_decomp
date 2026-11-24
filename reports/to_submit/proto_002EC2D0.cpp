// bin: proto
// va: 0x002EC2D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC2D0 (Proto 0x002EC2D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004274F4[];
extern "C" Object DAT_00462C48;
extern "C" char sub_001E5B70[];

void __cdecl sub_002EC2D0(void)
{
    DAT_00462C48.sub_00065550(0, (int)DAT_004274F4, (int)sub_001E5B70, 0, 2, 2);
}
