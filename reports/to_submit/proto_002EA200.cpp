// bin: proto
// va: 0x002EA200
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EA200 (Proto 0x002EA200, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041948C[];
extern "C" char DAT_0041949C[];
extern "C" Object DAT_00461604;
extern "C" char sub_001C1E10[];

void __cdecl sub_002EA200(void)
{
    DAT_00461604.sub_00065550((int)DAT_0041949C, (int)DAT_0041948C, (int)sub_001C1E10, 0, 3, 3);
}
