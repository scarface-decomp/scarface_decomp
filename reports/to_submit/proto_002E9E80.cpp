// bin: proto
// va: 0x002E9E80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9E80 (Proto 0x002E9E80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0041814C[];
extern "C" char DAT_00418168[];
extern "C" Object DAT_0046108C;
extern "C" char sub_001B4AA0[];

void __cdecl sub_002E9E80(void)
{
    DAT_0046108C.sub_000654B0((int)DAT_00418168, (int)DAT_0041814C, (int)sub_001B4AA0, 0, 2, 2);
}
