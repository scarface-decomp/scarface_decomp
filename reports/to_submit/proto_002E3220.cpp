// bin: proto
// va: 0x002E3220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3220 (Proto 0x002E3220, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_003FE998[];
extern "C" Object DAT_0045434C;
extern "C" char sub_0008D650[];

void __cdecl sub_002E3220(void)
{
    DAT_0045434C.sub_00065500(0, (int)DAT_003FE998, (int)sub_0008D650, 0, 2, 2);
}
