// bin: proto
// va: 0x002ECB50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECB50 (Proto 0x002ECB50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0042787C[];
extern "C" Object DAT_0046305C;
extern "C" char sub_001EE9C0[];

void __cdecl sub_002ECB50(void)
{
    DAT_0046305C.sub_00065550(0, (int)DAT_0042787C, (int)sub_001EE9C0, 0, 1, 1);
}
