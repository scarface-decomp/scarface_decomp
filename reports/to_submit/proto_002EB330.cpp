// bin: proto
// va: 0x002EB330
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB330 (Proto 0x002EB330, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425F64[];
extern "C" char DAT_00425F78[];
extern "C" Object DAT_00461B24;
extern "C" char sub_001DABF0[];

void __cdecl sub_002EB330(void)
{
    DAT_00461B24.sub_00065550((int)DAT_00425F78, (int)DAT_00425F64, (int)sub_001DABF0, 0, 4, 4);
}
