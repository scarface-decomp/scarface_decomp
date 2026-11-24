// bin: proto
// va: 0x002E7210
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7210 (Proto 0x002E7210, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040FF18[];
extern "C" char DAT_0040FF30[];
extern "C" Object DAT_0045ED9C;
extern "C" char sub_00189BC0[];

void __cdecl sub_002E7210(void)
{
    DAT_0045ED9C.sub_00065550((int)DAT_0040FF30, (int)DAT_0040FF18, (int)sub_00189BC0, 0, 2, 2);
}
