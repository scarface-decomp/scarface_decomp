// bin: proto
// va: 0x002E58E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E58E0 (Proto 0x002E58E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_00409C2C[];
extern "C" char DAT_00409C3C[];
extern "C" Object DAT_0045C698;
extern "C" char sub_00141BB0[];

void __cdecl sub_002E58E0(void)
{
    DAT_0045C698.sub_00065500((int)DAT_00409C3C, (int)DAT_00409C2C, (int)sub_00141BB0, 0, 2, 2);
}
