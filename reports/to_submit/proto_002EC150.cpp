// bin: proto
// va: 0x002EC150
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC150 (Proto 0x002EC150, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_0042738C[];
extern "C" Object DAT_00462A38;
extern "C" char sub_001E59C0[];

void __cdecl sub_002EC150(void)
{
    DAT_00462A38.sub_00065500(0, (int)DAT_0042738C, (int)sub_001E59C0, 0, 1, 1);
}
