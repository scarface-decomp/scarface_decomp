// bin: proto
// va: 0x002E81F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E81F0 (Proto 0x002E81F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411788[];
extern "C" char DAT_0041179C[];
extern "C" Object DAT_0045FD40;
extern "C" char sub_0018BC30[];

void __cdecl sub_002E81F0(void)
{
    DAT_0045FD40.sub_00065550((int)DAT_0041179C, (int)DAT_00411788, (int)sub_0018BC30, 0, 3, 5);
}
