// bin: proto
// va: 0x002EB4F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB4F0 (Proto 0x002EB4F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0042612C[];
extern "C" char DAT_0042613C[];
extern "C" Object DAT_00461D8C;
extern "C" char sub_001DA810[];

void __cdecl sub_002EB4F0(void)
{
    DAT_00461D8C.sub_00065550((int)DAT_0042613C, (int)DAT_0042612C, (int)sub_001DA810, 0, 4, 4);
}
