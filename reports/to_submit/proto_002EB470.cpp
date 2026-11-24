// bin: proto
// va: 0x002EB470
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB470 (Proto 0x002EB470, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004260B4[];
extern "C" char DAT_004260C4[];
extern "C" Object DAT_00461CDC;
extern "C" char sub_001DA7E0[];

void __cdecl sub_002EB470(void)
{
    DAT_00461CDC.sub_00065550((int)DAT_004260C4, (int)DAT_004260B4, (int)sub_001DA7E0, 0, 3, 3);
}
