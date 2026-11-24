// bin: proto
// va: 0x002E9C40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9C40 (Proto 0x002E9C40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00417B5C[];
extern "C" char DAT_00417B70[];
extern "C" Object DAT_00460E78;
extern "C" char sub_0018AF30[];

void __cdecl sub_002E9C40(void)
{
    DAT_00460E78.sub_00065550((int)DAT_00417B70, (int)DAT_00417B5C, (int)sub_0018AF30, 0, 2, 2);
}
