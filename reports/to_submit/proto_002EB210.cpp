// bin: proto
// va: 0x002EB210
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB210 (Proto 0x002EB210, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425E48[];
extern "C" char DAT_00425E58[];
extern "C" Object DAT_00461998;
extern "C" char sub_001DA9B0[];

void __cdecl sub_002EB210(void)
{
    DAT_00461998.sub_00065550((int)DAT_00425E58, (int)DAT_00425E48, (int)sub_001DA9B0, 0, 3, 3);
}
