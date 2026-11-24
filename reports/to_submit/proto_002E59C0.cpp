// bin: proto
// va: 0x002E59C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E59C0 (Proto 0x002E59C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00409E04[];
extern "C" char DAT_00409E14[];
extern "C" Object DAT_0045C780;
extern "C" char sub_00142520[];

void __cdecl sub_002E59C0(void)
{
    DAT_0045C780.sub_000654B0((int)DAT_00409E14, (int)DAT_00409E04, (int)sub_00142520, 0, 3, 3);
}
