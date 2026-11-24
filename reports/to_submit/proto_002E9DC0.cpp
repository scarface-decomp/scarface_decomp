// bin: proto
// va: 0x002E9DC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9DC0 (Proto 0x002E9DC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00418064[];
extern "C" char DAT_00418078[];
extern "C" Object DAT_00460F84;
extern "C" char sub_001B4A10[];

void __cdecl sub_002E9DC0(void)
{
    DAT_00460F84.sub_000654B0((int)DAT_00418078, (int)DAT_00418064, (int)sub_001B4A10, 0, 2, 2);
}
