// bin: proto
// va: 0x002EC2F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC2F0 (Proto 0x002EC2F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0042751C[];
extern "C" Object DAT_00462C74;
extern "C" char sub_001E5B90[];

void __cdecl sub_002EC2F0(void)
{
    DAT_00462C74.sub_00065550(0, (int)DAT_0042751C, (int)sub_001E5B90, 0, 2, 2);
}
