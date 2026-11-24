// bin: proto
// va: 0x002E58A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E58A0 (Proto 0x002E58A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409B54[];
extern "C" char DAT_00409B68[];
extern "C" Object DAT_0045C66C;
extern "C" char sub_00141A70[];

void __cdecl sub_002E58A0(void)
{
    DAT_0045C66C.sub_00065550((int)DAT_00409B68, (int)DAT_00409B54, (int)sub_00141A70, 0, 3, 3);
}
